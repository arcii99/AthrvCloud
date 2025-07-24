//FormAI DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {

    char* message = "Greetings, from Process 1!";

    // Generate a key for shared memory segment
    key_t key = ftok(".", 'A');

    // Create shared memory segment
    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    // Attach the shared memory segment to this process
    char* shared_memory = (char*)shmat(shm_id, NULL, 0);

    // Copy the message to shared memory segment
    sprintf(shared_memory, "%s", message);

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        printf("Error forking child process!\n");
        exit(1);
    }

    if (pid == 0) { // Child process
        printf("Child process executing...\n");

        // Retrieve shared memory segment
        char* shared_memory = (char*)shmat(shm_id, NULL, 0);

        // Print message from parent process
        printf("Message from parent process: %s\n", shared_memory);

        // Modify shared memory segment
        sprintf(shared_memory, "Greetings, from Process 2!");

        // Detach shared memory segment
        shmdt(shared_memory);

        // Exit child process
        exit(0);
    }
    else { // Parent process
        printf("Parent process executing...\n");

        wait(NULL); // Wait for child process to complete

        // Retrieve shared memory segment
        char* shared_memory = (char*)shmat(shm_id, NULL, 0);

        // Print modified message
        printf("Message after modification: %s\n", shared_memory);

        // Detach shared memory segment
        shmdt(shared_memory);

        // Remove shared memory segment
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}