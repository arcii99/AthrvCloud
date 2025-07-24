//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF 1024

int main()
{
    pid_t pid;
    int fd[2];
    char buf[MAX_BUF];
    
    // Create the pipe
    if (pipe(fd) == -1) {
        perror("Pipe");
        return EXIT_FAILURE;
    }
    
    // Create a child process
    pid = fork();
    
    if (pid < 0) {
        perror("Fork");
        return EXIT_FAILURE;
    }
    
    if (pid == 0) { // Child process
        close(fd[0]); // Close unused read end
        
        // Write a surrealist message to the pipe
        char* message = "The cat ate the moon, and the stars danced in delight!";
        if (write(fd[1], message, MAX_BUF) == -1) {
            perror("Write");
            return EXIT_FAILURE;
        }
        
        close(fd[1]); // Close write end
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(fd[1]); // Close unused write end
        
        // Read the surrealist message from the pipe
        if (read(fd[0], buf, MAX_BUF) == -1) {
            perror("Read");
            return EXIT_FAILURE;
        }
        printf("Received message from child: %s\n", buf);
        
        int status;
        waitpid(pid, &status, 0); // Wait for child process to complete
        close(fd[0]); // Close read end
    }
    
    return EXIT_SUCCESS;
}