//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

#define MAX_SIZE 1024

int main(){
    // Create a FIFO file
    mkfifo("fifo_file", 0666);

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // Child process
    else if (pid == 0)
    {
        printf("\nChild process is running\n");

        // Open the FIFO file in write mode        
        int fifo_fd = open("fifo_file", O_WRONLY);

        if(fifo_fd < 0){
            perror("Error in opening FIFO file");
            exit(EXIT_FAILURE);
        }

        // Send some data through the FIFO
        char message1[MAX_SIZE] = "Hello from the child process!";
        write(fifo_fd, message1, strlen(message1)+1);

        // Close the file descriptor
        close(fifo_fd);

        printf("\nChild process completed\n");

        exit(EXIT_SUCCESS);
    }

    // Parent process
    else
    {
        printf("\nParent process is running\n");

        // Open the FIFO file in read mode
        int fifo_fd = open("fifo_file", O_RDONLY);

        if(fifo_fd < 0){
            perror("Error in opening FIFO file");
            exit(EXIT_FAILURE);
        }

        // Read data from FIFO
        char message2[MAX_SIZE];
        read(fifo_fd, message2, MAX_SIZE);

        // Print the message
        printf("\nReceived message from child process : %s\n", message2);

        // Close the file descriptor
        close(fifo_fd);

        // Wait for child process
        wait(NULL);

        // Remove the FIFO file
        remove("fifo_file");

        printf("\nParent process completed\n");
        
        exit(EXIT_SUCCESS);
    }
}