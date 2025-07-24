//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_BUF 1024

int main()
{
    int fd1, fd2;
    char * myfifo1 = "/tmp/cyber_fifo1";
    char * myfifo2 = "/tmp/cyber_fifo2";
    char buf[MAX_BUF];
    pid_t pid;

    // Create FIFOs
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    // Child process
    if (pid == 0) {
        // Open both FIFOs for writing
        fd1 = open(myfifo1, O_WRONLY);
        fd2 = open(myfifo2, O_WRONLY);

        // Write a message to the parent process
        strcpy(buf, "Greetings from the Cyberpunk Child Process!");
        write(fd1, buf, sizeof(buf));

        // Sleep for a second to simulate some work
        sleep(1);

        // Write another message to the parent process
        strcpy(buf, "Ending communication with the parent process.");
        write(fd2, buf, sizeof(buf));

        exit(0);
    }
    // Parent process
    else {
        // Open both FIFOs for reading
        fd1 = open(myfifo1, O_RDONLY);
        fd2 = open(myfifo2, O_RDONLY);

        // Read messages from the child process
        read(fd1, buf, sizeof(buf));
        printf("Received message from child: %s\n", buf);

        // Wait for the child process to finish
        wait(NULL);

        // Read the second message from the child process
        read(fd2, buf, sizeof(buf));
        printf("Received message from child: %s\n", buf);

        // Clean up
        close(fd1);
        close(fd2);
        unlink(myfifo1);
        unlink(myfifo2);
    }

    return 0;
}