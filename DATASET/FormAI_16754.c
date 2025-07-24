//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    int *shm_ptr;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    shm_ptr = (int*) shmat(shmid, NULL, 0);
    if ((int) shm_ptr == -1) {
        perror("shmat failed");
        exit(1);
    }

    *shm_ptr = 0;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process waiting for data...\n");
        while (*shm_ptr == 0); // Wait for data
        printf("Child process received data: %d\n", *shm_ptr);
        *shm_ptr = *shm_ptr * 2;
        printf("Child process modified data: %d\n", *shm_ptr);
        exit(0);
    } else {
        // Parent process
        printf("Parent process sending data...\n");
        *shm_ptr = 42;
        printf("Parent process sent data: %d\n", *shm_ptr);
        printf("Parent process waiting for child to finish...\n");
        wait(NULL);
        printf("Parent process received modified data: %d\n", *shm_ptr);
    }

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}