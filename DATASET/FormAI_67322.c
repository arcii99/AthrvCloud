//FormAI DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main() {
    pid_t pid;              
    int pfd[2];             
    char pipe_buffer[BUFFER_SIZE];  
    char message[] = "I'll always be here to listen to what you have to say.\n";
  
    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
  
    pid = fork();     
  
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
  
    if (pid == 0) {   
        close(pfd[1]);  
        memset(pipe_buffer, 0, BUFFER_SIZE); 
        read(pfd[0], pipe_buffer, BUFFER_SIZE);
        printf("Process 2: %s", pipe_buffer);
        close(pfd[0]);  
        exit(EXIT_SUCCESS);
    } else {           
        close(pfd[0]);  
        write(pfd[1], message, strlen(message) + 1);
        close(pfd[1]);  
        printf("Process 1: Sent message to Process 2.\n");
        wait(NULL);    
        exit(EXIT_SUCCESS);
    }
}