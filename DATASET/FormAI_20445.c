//FormAI DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_MSG_LENGTH 1024

int main(int argc, char *argv[]) {
    int pid1, pid2; 
    int fd1, fd2;
    char msg[MAX_MSG_LENGTH];

    mkfifo("pipe1", 0666); // create the pipes
    mkfifo("pipe2", 0666);

    pid1 = fork(); // create the first child process
    if (pid1 < 0) {
        perror("failed to fork process 1\n");
        exit(1);
    } else if (pid1 == 0) { // child 1
        fd1 = open("pipe1", O_RDONLY);
        while (1) { // continuously read messages from pipe 1 and print them
            read(fd1, msg, MAX_MSG_LENGTH);
            printf("Process 1 received: %s", msg);
            fflush(stdout);
        }
    } else { // parent
        pid2 = fork(); // create the second child process
        if (pid2 < 0) {
            perror("failed to fork process 2\n");
            exit(1);
        } else if (pid2 == 0) { // child 2
            fd2 = open("pipe2", O_RDONLY);
            while (1) { // continuously read messages from pipe 2 and print them
                read(fd2, msg, MAX_MSG_LENGTH);
                printf("Process 2 received: %s", msg);
                fflush(stdout);
            }
        } else { // parent
            fd1 = open("pipe1", O_WRONLY); // parent writes to pipe 1 and reads from pipe 2
            fd2 = open("pipe2", O_WRONLY);

            while (1) { // continuously read input from user and write it to the appropriate pipe
                printf("Enter message: ");
                fflush(stdout);

                fgets(msg, MAX_MSG_LENGTH, stdin);

                if (strncmp(msg, "1", 1) == 0) {
                    write(fd1, msg, strlen(msg) + 1);
                } else if (strncmp(msg, "2", 1) == 0) {
                    write(fd2, msg, strlen(msg) + 1);
                } else {
                    printf("Invalid command, try again.\n");
                    fflush(stdout);
                }
            }
        }
    }

    return 0;
}