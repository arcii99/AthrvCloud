//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

    // Creating the pipe using mkfifo()
    mkfifo("my_pipe", 0666);

    // Opening the pipe for reading and writing
    int fd = open("my_pipe", O_RDWR);

    // Writing to the pipe
    char write_message[] = "Hello world!";
    write(fd, write_message, sizeof(write_message));

    // Reading from the pipe
    char read_message[100];
    read(fd, read_message, sizeof(read_message));

    // Printing the read message
    printf("Message received: %s", read_message);

    // Closing the pipe and deleting the file
    close(fd);
    unlink("my_pipe");

    return 0;
}