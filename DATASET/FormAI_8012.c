//FormAI DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10

int main() {
    int pid[MAX_PROCESSES];
    int status[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        pid_t child_pid = fork();

        if (child_pid == 0) {
            // Child process
            sleep(1);
            exit(0);
        } else if (child_pid == -1) {
            // Fork failed
            printf("Fork failed\n");
            break;
        } else {
            // Parent process
            pid[num_processes] = child_pid;
            num_processes++;
        }
    }

    // Check performance of each process
    for (int i = 0; i < num_processes; i++) {
        waitpid(pid[i], &status[i], 0);

        if (WIFEXITED(status[i])) {
            // Child process exited normally
            int exit_status = WEXITSTATUS(status[i]);

            printf("Process %d exited with status %d\n", i, exit_status);
        } else if (WIFSIGNALED(status[i])) {
            // Child process was terminated by a signal
            int signal_number = WTERMSIG(status[i]);

            printf("Process %d terminated with signal %d\n", i, signal_number);
        }
    }

    return 0;
}