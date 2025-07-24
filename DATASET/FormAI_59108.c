//FormAI DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>

void printStatus(int status) {
    if (WIFEXITED(status)) {
        printf("Exit status: %d\n", WEXITSTATUS(status));
    }
    else {
        printf("Termination signal: %d\n", WTERMSIG(status));
    }
}

void daemonize() {
    pid_t pid,sid;
    int fd;

    pid=fork();
    if(pid<0){
        fprintf(stderr,"Fork failed.\n");
        exit(EXIT_FAILURE);
    }
    if (pid > 0){
        printf("PID of child process: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid=setsid();
    if(sid < 0){
        fprintf(stderr, "Session creation failed.\n");
        exit(EXIT_FAILURE);
    }

    if(chdir("/")<0){
        fprintf(stderr, "Unable to change working directory.\n");
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    fd=open("/dev/null",O_RDWR);
    dup2(fd,STDIN_FILENO);
    dup2(fd,STDOUT_FILENO);
    dup2(fd,STDERR_FILENO);
}

int main() {
    int status;

    daemonize();

    while(1) {
        pid_t pid = fork();
        if(pid < 0) {
            printf("Fork failed\n");
            exit(EXIT_FAILURE);
        }
        if(pid == 0) {
            printf("Child ID: %d\n", getpid());
            sleep(10);
            exit(EXIT_SUCCESS);
        }
        else {
            printf("Parent ID: %d\n", getpid());
            waitpid(pid, &status, 0);
            printf("Child process terminated\n");
            printStatus(status);
            sleep(5);
        }
    }
    return 0;
}