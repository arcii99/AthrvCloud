//FormAI DATASET v1.0 Category: System administration ; Style: systematic
#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    int fd[2];
    
    // Creating pipe
    if(pipe(fd) < 0) {
        perror("Pipe creation failed");
        return 1;
    }
    
    // Forking a child process
    pid = fork();
    if(pid < 0) {
        perror("Forking failed");
        return 1;
    }
    
    if(pid == 0) {
        // Child process
        close(fd[0]); // Close read end of pipe
        
        // Redirecting standard output to the pipe
        if(dup2(fd[1], STDOUT_FILENO) < 0) {
            perror("Error in dup2");
            return 1;
        }
        
        // Executing the system command to get CPU usage
        if(execlp("/usr/bin/top", "top", "-bn1", NULL) < 0) {
            perror("Error in exec");
            return 1;
        }
    } else {
        // Parent process
        close(fd[1]); // Close write end of pipe
        
        char buffer[1024];
        int bytes_read = read(fd[0], buffer, 1024); // Reading from pipe
        printf("CPU usage:\n%s\n", buffer); // Printing CPU usage
    }
    
    return 0;
}