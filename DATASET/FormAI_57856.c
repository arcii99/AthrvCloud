//FormAI DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 256
#define PIPE_NAME "/tmp/example_pipe"

int main(){
    pid_t pid;
    int pipe_fd, nbytes;
    char buffer[BUFFER_SIZE];

    /* Create named pipe */
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("Error creating named pipe");
        exit(EXIT_FAILURE);
    }

    /* Fork a child process */
    pid = fork();

    if(pid == -1){
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        /* Child process */
        printf("Child process\n");

        /* Open the named pipe for writing */
        pipe_fd = open(PIPE_NAME, O_WRONLY);

        /* Write a message to the named pipe */
        char msg[] = "Greetings from the child process\n";
        write(pipe_fd, msg, strlen(msg));

        /* Close the named pipe */
        close(pipe_fd);

        /* Exit child process */
        exit(EXIT_SUCCESS);
    }
    else{
        /* Parent process */
        printf("Parent process\n");

        /* Open the named pipe for reading */
        pipe_fd = open(PIPE_NAME, O_RDONLY);

        /* Read from the named pipe */
        nbytes = read(pipe_fd, buffer, BUFFER_SIZE);
        printf("Received message: %s", buffer);

        /* Close the named pipe */
        close(pipe_fd);

        /* Remove the named pipe */
        if (unlink(PIPE_NAME) == -1) {
            perror("Error removing named pipe");
            exit(EXIT_FAILURE);
        }

        /* Wait for child process to exit */
        wait(NULL);

        /* Exit parent process */
        exit(EXIT_SUCCESS);
    }

    return 0;
}