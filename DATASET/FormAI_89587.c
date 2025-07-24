//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void async_read(int fd, char *buffer, int size, void (*callback)(char*))
{
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    int bytes_read = read(fd, buffer, size);

    if (bytes_read == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return;
        } else {
            perror("read");
            exit(EXIT_FAILURE);
        }
    } else if (bytes_read == 0) {
        close(fd);
        return;
    } else {
        callback(buffer);
    }
}

void async_write(int fd, char *buffer, int size)
{
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    int bytes_written = write(fd, buffer, size);

    if (bytes_written == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return;
        } else {
            perror("write");
            exit(EXIT_FAILURE);
        }
    } else if (bytes_written == 0) {
        close(fd);
        return;
    }
}

void handle_read(char *buffer)
{
    printf("Received: '%s'\n", buffer);
}

int main()
{
    int fd = open("example.txt", O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE] = {0};

    while(true) {
        async_read(fd, buffer, BUFFER_SIZE, handle_read);
        async_write(fd, "Processed", 9);
        sleep(1);
    }

    close(fd);
    return EXIT_SUCCESS;
}