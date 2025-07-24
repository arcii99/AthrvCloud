//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int process_id, child_process_id, i = 0;
    printf("Enter the number of child processes: ");
    scanf("%d", &child_process_id);

    while (i < child_process_id) {
        if (fork() == 0) {
            printf("I'm the %dth child with PID: %d\n", i + 1, getpid());
            printf("My parent PID is: %d\n\n", getppid());
            exit(0);
        }
        i++;
    }

    for (i = 0; i < child_process_id; i++) {
        process_id = wait(NULL);
        printf("Child with PID: %d has terminated\n", process_id);
    }
    
    printf("All child processes have terminated. Parent process terminating.\n");

    return 0;
}