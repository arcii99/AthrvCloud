//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MESSAGE_SIZE 256

int main() {
    // create the named pipe file
    mkfifo("myfifo", 0666);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        char message[MESSAGE_SIZE];
        int fd = open("myfifo", O_RDONLY);

        read(fd, message, MESSAGE_SIZE);
        printf("Child received message from parent: '%s'\n", message);

        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        // parent process
        char message[MESSAGE_SIZE] = "Hello from parent!";
        int fd = open("myfifo", O_WRONLY);

        write(fd, message, strlen(message));
        printf("Parent sent message to child: '%s'\n", message);

        close(fd);

        waitpid(pid, NULL, 0);
    }

    return 0;
}