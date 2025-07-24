//FormAI DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char *command1[] = { "/bin/ls", "-la", NULL };
    char *command2[] = { "/usr/bin/grep", "example", NULL };
    char *command3[] = { "/usr/bin/sort", NULL };
    
    int fd[2];
    if (pipe(fd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    int pid_ls = fork();
    if (pid_ls == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid_ls == 0){
        if (dup2(fd[1], STDOUT_FILENO) == -1){
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(fd[0]);
        execvp(command1[0], command1);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    
    int pid_grep = fork();
    if (pid_grep == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid_grep == 0){
        if (dup2(fd[0], STDIN_FILENO) == -1){
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(fd[1]);
        execvp(command2[0], command2);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    
    close(fd[0]);
    close(fd[1]);
    
    int pid_sort = fork();
    if (pid_sort == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid_sort == 0){
        execvp(command3[0], command3);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    
    while (wait(NULL) > 0);
    return 0;
}