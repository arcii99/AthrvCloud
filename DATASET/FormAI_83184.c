//FormAI DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shmid;
    char* shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Failed to create shared memory!");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char*) -1) {
        perror("Failed to attach to shared memory!");
        exit(1);
    }

    // Write message to shared memory
    sprintf(shmptr, "Hello, Interprocess Communication!");

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("Failed to fork!");
        exit(1);
    } else if (pid == 0) {
        // Child process reads message from shared memory
        printf("Child process reads message: %s\n", shmptr);

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("Failed to detach from shared memory!");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("Failed to delete shared memory!");
            exit(1);
        }

        exit(0);
    } else {
        // Parent process waits for child to finish
        wait(NULL);
        printf("Parent process has completed!\n");

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("Failed to detach from shared memory!");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("Failed to delete shared memory!");
            exit(1);
        }

        exit(0);
    }

    return 0;
}