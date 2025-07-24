//FormAI DATASET v1.0 Category: Interprocess communication ; Style: systematic
// C Interprocess communication example program

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 // Size of the shared memory segment

int main() {
    int shmid;
    key_t key;
    char *shm_ptr;

    // Generate a unique key for the shared memory segment
    key = ftok(".", 's');

    // Create the shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    if ((shm_ptr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a string to the shared memory segment
    printf("Enter a string to write to the shared memory segment: ");
    fgets(shm_ptr, SHM_SIZE, stdin);

    // Read the string from the shared memory segment
    printf("The string in the shared memory segment is: %s\n", shm_ptr);

    // Detach the shared memory segment
    shmdt(shm_ptr);

    // Delete the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    // Exit the program
    return 0;
}