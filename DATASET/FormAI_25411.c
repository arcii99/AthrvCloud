//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    //fork a child process
    pid_t pid = fork();

    if(pid < 0){
        printf("Fork failed\n");
        return -1;
    }
    else if(pid == 0){ //child process
        printf("Child process ID: %d\n", getpid());
        //execute system command to install nginx web server
        execl("/usr/bin/apt-get", "apt-get", "update", "-y", NULL);
        execl("/usr/bin/apt-get", "apt-get", "install", "nginx", "-y", NULL);
        printf("Installation completed\n");
    }
    else{ //parent process
        printf("Parent process ID: %d\n", getpid());
        int status;
        waitpid(pid, &status, 0); //wait for child process to complete
        if(WIFEXITED(status)){
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
            //execute system command to start nginx service
            execl("/usr/sbin/service", "service", "nginx", "start", NULL);
            printf("Nginx started successfully\n");
        }
    }
    return 0;
}