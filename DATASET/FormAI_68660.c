//FormAI DATASET v1.0 Category: Funny ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

void async_read(int fd, char* buffer, int size) {
    int n = read(fd, buffer, size);
    printf("Read %d bytes from file\n", n);
}

void async_write(int fd, char* buffer, int size) {
    int n = write(fd, buffer, size);
    printf("Wrote %d bytes to file\n", n);
}

void async_sleep(int seconds) {
    printf("Sleeping for %d seconds...\n", seconds);
    sleep(seconds);
    printf("Waking up from sleep\n");
}

int main() {
    srand(time(NULL));
    int fd = open("output.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    char write_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    for(int i=0; i<BUFFER_SIZE; i++) {
        write_buffer[i] = rand() % 26 + 'a';
    }

    async_write(fd, write_buffer, BUFFER_SIZE);
    async_sleep(3);

    async_read(fd, read_buffer, BUFFER_SIZE);
    async_sleep(2);

    printf("Read text from file: %s\n", read_buffer);

    close(fd);
    return 0;
}