//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<fcntl.h>
#include<string.h>

#define BUFFER_SIZE 1024

pid_t pid; //process ID
int count;
int readfd, writefd;
char *fifo1 = "fifo1";
char *fifo2 = "fifo2";
char buffer[BUFFER_SIZE];

void sigHandler(int signum) {
    printf("\nChild process terminated. Parent process exiting...\n");
    close(readfd);
    close(writefd);
    unlink(fifo1);
    unlink(fifo2);
    exit(0);
}

int main() {

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    pid = fork();

    if (pid == 0) { 
        //Child process
        signal(SIGINT, SIG_DFL);
        //Open read and write pipes
        readfd = open(fifo1, O_RDONLY);
        writefd = open(fifo2, O_WRONLY);

        while (1) {
            //Read from parent process
            read(readfd, buffer, BUFFER_SIZE);
            if (strcmp(buffer, "exit") == 0)
                break;
            printf("\nParent sent: %s", buffer);

            //Process data
            count = strlen(buffer) - 1;
            if (buffer[count] == '\n')
                buffer[count] = '\0';
        
            //Write to parent process
            write(writefd, buffer, BUFFER_SIZE);
            printf("\nChild sent processed data: %s", buffer);
        }
        exit(0);
    } 
    else { 
        //Parent process
        signal(SIGINT, sigHandler);
        //Open read and write pipes
        readfd = open(fifo2, O_RDONLY);
        writefd = open(fifo1, O_WRONLY);

        do {
            //Read input from user
            printf("\nEnter data: ");
            fgets(buffer, BUFFER_SIZE, stdin);

            //Write input to child process
            write(writefd, buffer, BUFFER_SIZE);

            //Read processed data from child process
            read(readfd, buffer, BUFFER_SIZE);
            printf("\nProcessed data: %s", buffer);

        } while (strcmp(buffer, "exit") != 0);

        //Send exit signal to child process
        write(writefd, "exit\n", BUFFER_SIZE);
        
        //Wait for child process to terminate
        wait(NULL);
        exit(0);
    }
}