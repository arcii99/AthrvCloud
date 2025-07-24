//FormAI DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

// Max number of processes to be spawned
#define MAX_PROCESS_COUNT 5

// Global variables to track the status of child processes
pid_t child_processes[MAX_PROCESS_COUNT];
bool is_process_running[MAX_PROCESS_COUNT];

// Handle SIGINT signal by killing all child processes
void handle_sigint(int sig) {
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        if (is_process_running[i]) {
            kill(child_processes[i], SIGKILL);
            is_process_running[i] = false;
        }
    }
    printf("All child processes killed\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    // Register signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    // Seed random number generator
    srand(time(NULL));

    // Spawn child processes
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        int pid = fork();
        if (pid == -1) {
            perror("Failed to fork child process");
            exit(1);
        } else if (pid == 0) {
            // Child process code
            printf("Child process %d started\n", getpid());
            // Sleep for a randomly generated time
            int sleep_time = rand() % 10 + 1;
            sleep(sleep_time);
            printf("Child process %d finished sleeping for %d seconds\n", getpid(), sleep_time);
            exit(0);
        } else {
            // Parent process code
            child_processes[i] = pid;
            is_process_running[i] = true;
        }
    }

    // Wait for all child processes to finish
    while (true) {
        bool all_processes_finished = true;
        for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
            if (is_process_running[i]) {
                int status;
                pid_t result = waitpid(child_processes[i], &status, WNOHANG);
                if (result == -1) {
                    perror("Failed to wait for child process");
                    is_process_running[i] = false;
                } else if (result == 0) {
                    all_processes_finished = false;
                } else {
                    if (WIFEXITED(status)) {
                        printf("Child process %d exited with status %d\n", child_processes[i], WEXITSTATUS(status));
                    } else if (WIFSIGNALED(status)) {
                        printf("Child process %d terminated by signal %d\n", child_processes[i], WTERMSIG(status));
                    }
                    is_process_running[i] = false;
                }
            }
        }
        if (all_processes_finished) {
            break;
        }
    }
    
    return 0;
}