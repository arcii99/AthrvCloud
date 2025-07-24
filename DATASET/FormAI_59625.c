//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    key_t key;
    int shm_id;
    char *shared_memory;

    key = ftok("ipc_example", 'a');
    shm_id = shmget(key, SIZE, IPC_CREAT | 0600);

    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    shared_memory = (char*) shmat(shm_id, NULL, 0);

    if (shared_memory == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process is writing to shared memory...\n");
        sprintf(shared_memory, "%s", "Hello, from the child process!");

        shmdt(shared_memory);
        printf("Child process has detached from shared memory.\n");
    } else {
        wait(NULL);

        printf("Parent process is reading from shared memory...\n");
        printf("Shared message: %s\n", shared_memory);

        shmdt(shared_memory);
        printf("Parent process has detached from shared memory.\n");
        shmctl(shm_id, IPC_RMID, NULL);
        printf("Shared memory has been removed.\n");
    }

    return 0;
}