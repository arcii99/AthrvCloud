//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<sys/wait.h>

//function to generate random number between given range
int generateRandomNumber(int minNum, int maxNum){
    return (rand() % (maxNum - minNum + 1)) + minNum;
}

//function to handle the signals
void signalHandler(int sigNum){
    printf("Received signal number %d\n", sigNum);
}

int main(){
    printf("Welcome to the System administration example program\n");
    srand(time(NULL));
    int status;

    //forking the child process
    pid_t child_pid = fork();

    if(child_pid == 0){
        printf("This is the child process running with process ID %d\n", getpid());

        //generating random signal number between 1 and 15
        int signalNum = generateRandomNumber(1, 15);

        sleep(5);
        printf("Sending signal number %d to parent process with ID %d\n", signalNum, getppid());

        //sending the signal to parent process
        kill(getppid(), signalNum);

        printf("Child process exiting\n");
        exit(0);
    }
    else{
        printf("This is the parent process running with process ID %d\n", getpid());

        //registering the signal handler functions
        signal(SIGINT, signalHandler);
        signal(SIGTSTP, signalHandler);
        signal(SIGTERM, signalHandler);
        signal(SIGUSR1, signalHandler);
        signal(SIGUSR2, signalHandler);

        printf("Parent process waiting for signal from child\n");

        //waiting for the signal from child process
        wait(&status);

        if(WIFSIGNALED(status)){
            printf("Parent process received signal number %d from child process\n", WTERMSIG(status));
        }

        printf("Parent process exiting\n");
        exit(0);
    }

    //program execution completed successfully
    return 0;
}