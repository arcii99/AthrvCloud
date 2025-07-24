//FormAI DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 512
#define READ_END 0
#define WRITE_END 1

int main(void) {
    char write_msg[BUFFER_SIZE] = "Greetings!";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    int status;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    // Child process
    else if (pid == 0) {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Child process received message: %s\n", read_msg);
        close(fd[READ_END]);

        int file_desc;
        char buffer[BUFFER_SIZE];
        memset(buffer, '\0', sizeof(buffer));
        file_desc = open("output.txt", O_WRONLY | O_CREAT, 0644);
        if (file_desc < 0) {
            fprintf(stderr, "Failed to create file 'output.txt'. Error: %s\n", strerror(errno));
            exit(1);
        }
        strcat(buffer, read_msg);

        if (write(file_desc, buffer, strlen(buffer)) == -1) {
            fprintf(stderr, "Failed to write to file 'output.txt'. Error: %s\n", strerror(errno));
        }
        close(file_desc);

    }
    // Parent process
    else {
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        printf("Parent process sent message: %s\n", write_msg);
        close(fd[WRITE_END]);
        waitpid(pid, &status, 0);
    }
    return 0;
}