//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void type_prompt()
{
    printf("> ");
}

int read_command(char* buffer)
{
    char* p = fgets(buffer, BUFFER_SIZE, stdin);
    if (!p) {
        return 0;
    } else {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        return 1;
    }
}

void execute_command(char** args)
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        int ret = execvp(args[0], args);
        if (ret == -1) {
            perror(args[0]);
            exit(1);
        }
    } else {
        int status;
        pid_t ret = waitpid(pid, &status, 0);
        if (ret == -1) {
            perror("waitpid");
        }
    }
}

int main(int argc, char** argv)
{
    while (1) {
        type_prompt();
        char buffer[BUFFER_SIZE];
        if (read_command(buffer)) {
            char* args[BUFFER_SIZE];
            char* p = strtok(buffer, " ");
            int i = 0;
            while (p) {
                args[i] = p;
                p = strtok(NULL, " ");
                i++;
            }
            args[i] = NULL;
            execute_command(args);
        } else {
            break;
        }
    }
    return 0;
}