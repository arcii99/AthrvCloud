//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

typedef enum {
    INIT = 0,
    RECORD_START,
    RECORD_END
} parser_state_t; 

typedef struct {
    int fd;
    bool processing;
    char buffer[BUFSIZ];
    size_t buffer_pos;
    int epoll_fd;
    struct epoll_event event;
    void (*callback)(const char **);
    parser_state_t state;
    const char *columns[3];
    char *csv_fields[3];
} csv_reader_t;

static bool
parse_csv_row(csv_reader_t *reader) {
    char *buffer = reader->buffer;
    const char **columns = reader->columns;
    char **csv_fields = reader->csv_fields;
    parser_state_t *current_state = &reader->state;
   
    while (*buffer != '\r' && *buffer != '\n' && *buffer != '\0') {
        switch (*current_state) {
            case INIT:
                *current_state = RECORD_START;
                csv_fields[0] = buffer;
                break;
            case RECORD_START:
                if (*buffer == ',') {
                    *buffer = '\0';
                    *current_state = RECORD_END;
                    csv_fields[1] = buffer + 1;
                }
                break;
            case RECORD_END:
                if (*buffer == ',') {
                    *buffer = '\0';
                    *current_state = RECORD_START;
                    csv_fields[2] = buffer + 1;
                }
                break;
        }

        buffer++;
    }

    if (*current_state != INIT) {
        csv_fields[2] = buffer - 1;
        *current_state = INIT;
        reader->callback(columns);
    }

    return true;
}

static void
csv_reader_callback(const char **fields) {
    printf("%s, %s, %s\n", fields[0], fields[1], fields[2]);
}

static void 
csv_reader_close(csv_reader_t *reader) {
    if (reader != NULL) {
        if (reader->fd >= 0) {
            close(reader->fd);
        }

        if (reader->epoll_fd >= 0) {
            close(reader->epoll_fd);
        }

        free(reader);
    }
}

static csv_reader_t *
csv_reader_new(const char *filename, void (*callback)(const char **)) {
    csv_reader_t *reader = (csv_reader_t *)calloc(1, sizeof(csv_reader_t));
    reader->callback = callback;

    reader->fd = open(filename, O_RDONLY);

    if (reader->fd < 0) {
        printf("Error opening %s: %s\n", filename, strerror(errno));
        csv_reader_close(reader);
        return NULL;
    }

    reader->epoll_fd = epoll_create1(0);

    if (reader->epoll_fd < 0) {
        printf("Error creating epoll: %s\n", strerror(errno));
        csv_reader_close(reader);
        return NULL;
    }

    reader->event.data.fd = reader->fd;
    reader->event.events = EPOLLIN | EPOLLRDHUP | EPOLLET;

    if (epoll_ctl(reader->epoll_fd, EPOLL_CTL_ADD, reader->fd, &reader->event) < 0) {
        printf("Error adding file descriptor to epoll: %s\n", strerror(errno));
        csv_reader_close(reader);
        return NULL;
    }

    return reader;
}

static bool
csv_reader_read_blocking(csv_reader_t *reader) {
    ssize_t bytes_read;
    bool ret = false;

    while ((bytes_read = read(reader->fd, reader->buffer + reader->buffer_pos, sizeof(reader->buffer) - reader->buffer_pos)) > 0) {
        reader->buffer_pos += bytes_read;

        if (reader->buffer_pos >= sizeof(reader->buffer)) {
            printf("Buffer overflow\n");
            csv_reader_close(reader);
            break;
        }
    }

    if (bytes_read == 0) {
        printf("End of file\n");
        ret = true;
    } else if (bytes_read < 0) {
        printf("Error reading from file: %s\n", strerror(errno));
        csv_reader_close(reader);
    } else {
        parse_csv_row(reader);

        if (reader->buffer_pos && reader->buffer[reader->buffer_pos - 1] == '\n') {
            reader->buffer_pos = 0;
        }
        ret = true;
    }

    return ret;
}

static bool
csv_reader_read_non_blocking(csv_reader_t *reader) {
    struct epoll_event events[MAX_EVENTS];
    int n;

    while (reader->processing) {
        n = epoll_wait(reader->epoll_fd, events, MAX_EVENTS, -1);

        for (int i = 0; i < n; i++) {
            if (events[i].events & EPOLLERR || events[i].events & EPOLLHUP) {
                printf("Error reading from file descriptor: %d\n", events[i].data.fd);
                csv_reader_close(reader);
                return false;
            }

            if (events[i].events & EPOLLIN) {
                if (csv_reader_read_blocking(reader)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int
main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename.csv]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    csv_reader_t *reader = csv_reader_new(argv[1], csv_reader_callback);
    reader->processing = true;

    if (reader == NULL) {
        exit(EXIT_FAILURE);
    }

    while (csv_reader_read_non_blocking(reader)) {}

    csv_reader_close(reader);
    exit(EXIT_SUCCESS);
}