//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complete
// A C program demonstrating Interprocess Communication using Pipes

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
    int fd[2]; 
    char input_string[100];
    pid_t pid;

    if (pipe(fd)==-1){
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }

    pid = fork();

    if (pid < 0){
        fprintf(stderr, "Fork Failed" );
        return 1;
    }

    else if (pid > 0) 
    {
        printf("Enter a string: ");
        scanf("%s", input_string);
        close(fd[0]); 
        write(fd[1], input_string, strlen(input_string)+1);
        close(fd[1]);
    }

    else 
    {
        char buffer[100];
        close(fd[1]); 
        read(fd[0], buffer, sizeof(buffer));
        printf("The input string is: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}