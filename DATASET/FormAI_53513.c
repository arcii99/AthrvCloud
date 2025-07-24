//FormAI DATASET v1.0 Category: Interprocess communication ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 4096

int main()
{
    int shm_id;
    char *shm_ptr;
    key_t shm_key = 1234;

    // Create shared memory
    shm_id = shmget(shm_key, SHM_SIZE, IPC_CREAT | 0666);

    // Attach shared memory segment to this process's address space
    shm_ptr = shmat(shm_id, NULL, 0);

    // Write to shared memory
    sprintf(shm_ptr, "Hello");

    // Fork a child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process reads from shared memory
        printf("Child process read from shared memory: %s\n", shm_ptr);

        // Write to shared memory
        sprintf(shm_ptr, "World");

        // Detach shared memory segment from child process's address space
        shmdt(shm_ptr);

        exit(0);
    } else if (pid > 0) {
        // Parent process waits for child process to finish
        wait(NULL);

        // Read from shared memory
        printf("Parent process read from shared memory: %s\n", shm_ptr);
    } else {
        printf("Failed to fork a child process.\n");
    }

    // Detach shared memory segment from parent process's address space
    shmdt(shm_ptr);

    // Remove shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}