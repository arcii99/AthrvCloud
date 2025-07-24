//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PIPE_NAME "my_pipe"

int main() {
    int fd1, fd2; // file descriptors for pipes
    char *message1 = "From Client: Hello Server, How are you?";
    char *message2 = "From Server: I am doing great. Thank you!";
    char buffer[BUFSIZ];
   
    // Create the pipe for sending data from client to server
    if (mkfifo(PIPE_NAME, 0666) < 0) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }
    printf("Pipe created successfully!\n");

    // Open pipe for writing
    fd1 = open(PIPE_NAME, O_WRONLY);

    // Write message to pipe
    write(fd1, message1, strlen(message1)+1);

    // Close the writing end of the pipe
    close(fd1);

    // Open the pipe for reading
    fd2 = open(PIPE_NAME, O_RDONLY);

    // Read message from the pipe
    read(fd2, buffer, BUFSIZ);
    printf("%s\n", buffer);

    // Close the reading end of the pipe
    close(fd2);

    // Unlink the named pipe
    unlink(PIPE_NAME);
    printf("Pipe unlinked successfully!\n");

    return 0;
}