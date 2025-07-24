//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void process_information(pid_t pid,char *pname) {
    printf("Process name: %s\t Process ID: %d\n",pname,pid);
}

int main() {
    pid_t pid1, pid2, pid3, pid4;
    int status;

    /*creating child process 1*/
    pid1 = fork();
    if(pid1 == 0) {
        //child process 1
        printf("Child Process 1 Running\n");
        sleep(2);
        printf("Child process 1 completed\n");
        exit(1);
    } else {
        process_information(pid1,"Process 1");
    }

    /*creating child process 2*/
    pid2 = fork();
    if(pid2 == 0) {
        //child process 2
        printf("Child Process 2 Running\n");
        sleep(3);
        printf("Child process 2 completed\n");
        exit(2);
    } else {
        process_information(pid2,"Process 2");
    }

    /*creating child process 3*/
    pid3 = fork();
    if(pid3 == 0) {
        //child process 3
        printf("Child Process 3 Running\n");
        sleep(4);
        printf("Child process 3 completed\n");
        exit(3);
    } else {
        process_information(pid3,"Process 3");
    }

    /*creating child process 4*/
    pid4 = fork();
    if(pid4 == 0) {
        //child process 4
        printf("Child Process 4 Running\n");
        sleep(5);
        printf("Child process 4 completed\n");
        exit(4);
    } else {
        process_information(pid4,"Process 4");
    }

    /*waiting for child processes to complete*/
    waitpid(pid1,&status,0);
    printf("Process 1 Status: %d\n",status);

    waitpid(pid2,&status,0);
    printf("Process 2 Status: %d\n",status);

    waitpid(pid3,&status,0);
    printf("Process 3 Status: %d\n",status);

    waitpid(pid4,&status,0);
    printf("Process 4 Status: %d\n",status);

    printf("Parent process completed\n");

    return 0;
}