//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#define READ_END 0
#define WRITE_END 1

int main() {
    int fd[2];
    pid_t pid;
    char message[] = "Hello, World!";
    char buffer[25];
    
    if (pipe(fd) == -1) {
        printf("Pipe Failed\n");
        return 1;
    }
    
    pid = fork();
    
    if (pid < 0) {
        printf("Fork Failed\n");
        return 1;
    }
    
    if (pid > 0) {
        /* Parent Process */
        close(fd[READ_END]);
        
        write(fd[WRITE_END], message, strlen(message) + 1);
        printf("\n[Parent Process] Sent Message: %s\n", message);
        
        wait(NULL);
        close(fd[WRITE_END]);
    }
    else {
        /* Child Process */
        close(fd[WRITE_END]);
        
        read(fd[READ_END], buffer, sizeof(buffer));
        printf("\n[Child Process] Received Message: %s\n", buffer);
        
        close(fd[READ_END]);
        exit(0);
    }
    
    return 0;
}