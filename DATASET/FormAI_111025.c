//FormAI DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMP_UPPER_LIMIT 80
#define REFRESH_INTERVAL 5

void monitor_temperature(pid_t pid);

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: Unable to fork the process\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        srand(time(NULL));
        int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Initial Temperature: %d°C\n", temp);
        while (true) {
            temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            printf("Temperature: %d°C\n", temp);
            if (temp >= TEMP_UPPER_LIMIT) {
                printf("Temperature Exceeds Upper Limit\n");
                exit(EXIT_SUCCESS);
            }
            sleep(REFRESH_INTERVAL);
        }
    } else {
        monitor_temperature(pid);
    }
    return 0;
}

void monitor_temperature(pid_t pid) {
    while (true) {
        sleep(REFRESH_INTERVAL);
        int status;
        pid_t result = waitpid(pid, &status, WNOHANG);
        if (result == 0) {
            printf("Temperature is still within range\n");
        } else if (result == -1) {
            printf("Error: Unable to wait for the child process\n");
            exit(EXIT_FAILURE);
        } else if (WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
            exit(EXIT_SUCCESS);
        }
    }
}