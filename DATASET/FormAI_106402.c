//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MSG_SIZE 100

int main() {
    int fd1[2], fd2[2];
    pid_t pid;
    char msg[MSG_SIZE];

    if (pipe(fd1) == -1) {
        printf("Pipe 1 failed\n");
        exit(1);
    }

    if (pipe(fd2) == -1) {
        printf("Pipe 2 failed\n");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    // Parent process
    if (pid > 0) {
        close(fd1[0]); // close reading end of pipe 1
        close(fd2[1]); // close writing end of pipe 2

        printf("Enter a message to send to child:\n");
        fgets(msg, MSG_SIZE, stdin);
        write(fd1[1], msg, strlen(msg)+1); // send message to child through pipe 1

        wait(NULL); // wait for child to finish

        read(fd2[0], msg, MSG_SIZE); // read message from child through pipe 2
        printf("Message received from child: %s\n", msg);

        close(fd1[1]);
        close(fd2[0]);
    }
    // Child process
    else {
        close(fd1[1]); // close writing end of pipe 1
        close(fd2[0]); // close reading end of pipe 2

        read(fd1[0], msg, MSG_SIZE); // read message from parent through pipe 1
        printf("Message received from parent: %s\n", msg);

        printf("Enter a message to send to parent:\n");
        fgets(msg, MSG_SIZE, stdin);
        write(fd2[1], msg, strlen(msg)+1); // send message to parent through pipe 2

        close(fd1[0]);
        close(fd2[1]);
        exit(0);
    }

    return 0;
}