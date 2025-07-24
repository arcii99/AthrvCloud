//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
    // Creating pipes
    mkfifo("pipe1", 0666);
    mkfifo("pipe2", 0666);

    // Writing data into pipe1
    int fd1 = open("pipe1", O_WRONLY);
    char *data = "Hello, I am Data!\n";
    write(fd1, data, strlen(data) + 1);
    close(fd1);

    // Reading data from pipe2
    int fd2 = open("pipe2", O_RDONLY);
    char buff[BUFF_SIZE];
    read(fd2, buff, BUFF_SIZE);
    printf("Received data from pipe2: %s", buff);
    close(fd2);

    // Cleanup pipes
    unlink("pipe1");
    unlink("pipe2");

    return 0;
}