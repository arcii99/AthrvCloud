//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 5

char *commands[MAX_COMMANDS][MAX_ARGS] = {{"ls", "-l", NULL}, {"pwd", NULL}, {"echo", "Hello, World!", NULL}};

int execute(char *args[]) {
    if (execvp(args[0], args) < 0) {
        perror("exec error");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int run_command(char *args[]) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork error");
    } else if (pid == 0) {
        return execute(args);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int main() {
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (commands[i][0] == NULL) {
            break;
        }
        run_command(commands[i]);
    }
    return 0;
}