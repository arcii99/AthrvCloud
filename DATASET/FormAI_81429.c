//FormAI DATASET v1.0 Category: Log analysis ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define FILENAME "example.log"

void handle_interrupt(int num);
void handle_read(int num);
void handle_write(int num);

int fd;
char buffer[BUFSIZE];
int lines = 0;

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_interrupt);

    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        ssize_t bytes_read = read(fd, buffer, BUFSIZE);
        if (bytes_read == -1) {
            if (errno == EINTR) {
                // interrupted, continue loop
                continue;
            } else {
                perror("read");
                exit(EXIT_FAILURE);
            }
        } else if (bytes_read == 0) {
            // end of file, exit loop
            break;
        }

        // spin off async read processing
        signal(SIGUSR1, handle_read);
        kill(getpid(), SIGUSR1);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}

void handle_interrupt(int num) {
    printf("Interrupted\n");
    close(fd);
    exit(EXIT_SUCCESS);
}

void handle_read(int num) {
    char *token;
    int i = 0;

    while ((token = strtok_r(buffer, "\n", &buffer))) {
        if (strstr(token, "Error") != NULL) {
            lines++;
            // spin off async write processing
            signal(SIGUSR1, handle_write);
            kill(getpid(), SIGUSR1);
        } else {
            i++;
        }
    }

    if (i == 0) {
        // empty buffer, exit processing
        return;
    }
}

void handle_write(int num) {
    char filename[BUFSIZE];
    snprintf(filename, sizeof(filename), "error-%d.log", lines);

    int fd_out = open(filename, O_WRONLY|O_CREAT, 0666);
    if (fd_out == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int bytes_written = write(fd_out, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    printf("Wrote %d bytes to %s\n", bytes_written, filename);

    close(fd_out);
}