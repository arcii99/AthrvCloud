//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
// A creative interprocess communication program
// This program demonstrates sending a secret message from a sender process to a receiver process through a shared memory

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment of size SHM_SIZE bytes
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("Failed to create shared memory segment");
        exit(1);
    }
    
    // Attach the shared memory segment to the process address space
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) -1) {
        perror("Failed to attach shared memory segment");
        exit(1);
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("Failed to fork");
        exit(1);
    }
    else if (pid == 0) {
        // This is the sender process
        char *secret_message = "The cake is a lie";
        sprintf(shm_ptr, "%s", secret_message);
        printf("Secret message sent: %s\n", secret_message);
        
        // Detach the shared memory segment
        shmdt(shm_ptr);
        
        // Exit the process
        exit(0);
    }
    else {
        // This is the receiver process
        printf("Waiting for secret message...\n");
        sleep(1);
        printf("Received secret message: %s\n", (char *) shm_ptr);
        
        // Detach the shared memory segment
        shmdt(shm_ptr);
        
        // Remove the shared memory segment
        shmctl(shm_id, IPC_RMID, NULL);
    }
    
    return 0;
}