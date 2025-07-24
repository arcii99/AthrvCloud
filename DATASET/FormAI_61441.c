//FormAI DATASET v1.0 Category: Task Scheduler ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

void task_1(){
    printf("Executing Task 1...\n");
}

void task_2(){
    printf("Executing Task 2...\n");
}

void task_3(){
    printf("Executing Task 3...\n");
}

void alarm_handler(int sig){
    printf("Alarm triggered...\n");

    // fork to create a child process
    pid_t pid = fork();

    // check for errors
    if(pid == -1){
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){ // this is the child process
        // execute the tasks one by one
        task_1();
        task_2();
        task_3();
        exit(EXIT_SUCCESS);
    }
    else{ // this is the parent process
        int child_status;
        pid_t child_pid;
        // wait for the child to terminate
        child_pid = wait(&child_status);

        // check for errors
        if(child_pid == -1){
            perror("Error in wait");
            exit(EXIT_FAILURE);
        }
        // check the exit status of the child process
        if(WIFEXITED(child_status)){
            printf("Child exited with status %d\n", WEXITSTATUS(child_status));
        }
        else if(WIFSIGNALED(child_status)){
            printf("Child terminated abnormally. Signal %d\n", WTERMSIG(child_status));
        }
    }
}

int main(){
    // set up the signal handler for SIGALRM
    struct sigaction sa;
    sa.sa_handler = &alarm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if(sigaction(SIGALRM, &sa, NULL) == -1){
        perror("Error in setting up signal handler");
        exit(EXIT_FAILURE);
    }

    // set up the alarm to trigger after 10 seconds
    alarm(10);

    while(1){
        // infinite loop to keep the program running
    }

    return 0;
}