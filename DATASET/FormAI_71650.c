//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024 // Shared memory size

int main() {
    pid_t pid;
    key_t key = 1234; // Shared memory key

    // Create shared memory segment
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    char *shm = (char *) shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // Child process
    else if (pid == 0) {
        printf("Child process is writing to shared memory...\n");
        sprintf(shm, "Hello from the child process!");

        printf("Child process wrote: %s\n", shm);

        exit(0);
    }

    // Parent process
    else {
        printf("Parent process is waiting for child process to finish...\n");
        wait(NULL);

        printf("Parent process read: %s\n", shm);
        printf("Parent process is detaching from shared memory and removing segment...\n");

        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}