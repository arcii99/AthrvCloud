//FormAI DATASET v1.0 Category: Interprocess communication ; Style: medieval
/* Medieval style program for interprocess communication */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(){

    int fd, status;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    pid_t pid;

    /* Create the named pipe for communication */
    mkfifo("/tmp/medieval_pipe", 0666);

    /* Fork a child process */
    pid = fork();

    if (pid < 0) {
        perror("Failed to fork child process");
        exit(1);
    } 
    else if (pid == 0) {
        /* Child process - read message from pipe */
        fd = open("/tmp/medieval_pipe", O_RDONLY);

        if (fd < 0) {
            perror("Failed to open named pipe");
            exit(1);
        }

        memset(buffer, 0, BUFFER_SIZE);
        status = read(fd, buffer, BUFFER_SIZE);

        if (status < 0) {
            perror("Failed to read from named pipe");
            exit(1);
        }

        printf("\nMessenger: '%s'\n", buffer);

        close(fd);
        exit(0);
    } else {
        /* Parent process - write message to pipe */
        fd = open("/tmp/medieval_pipe", O_WRONLY);

        if (fd < 0) {
            perror("Failed to open named pipe");
            exit(1);
        }

        printf("Enter your message (max %d characters):\n", BUFFER_SIZE);
        fgets(message, BUFFER_SIZE, stdin);

        status = write(fd, message, strlen(message));

        if (status < 0) {
            perror("Failed to write to named pipe");
            exit(1);
        }

        printf("Messenger: '%s' sent!\n", message);

        close(fd);
        exit(0);
    }
    return 0;
}