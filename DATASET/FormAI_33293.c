//FormAI DATASET v1.0 Category: Interprocess communication ; Style: peaceful
/* This program demonstrates interprocess communication between a parent and child process using semaphores */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 1234 // Key for semaphore set
#define P(X) semop(X, &pop, 1) // Macro for performing a semaphore P operation
#define V(X) semop(X, &vop, 1) // Macro for performing a semaphore V operation

// Struct for semaphore operations
struct sembuf pop = {0, -1, SEM_UNDO};
struct sembuf vop = {0, 1, SEM_UNDO};

int main() {
    // Create a semaphore set with a single semaphore
    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("Error creating semaphore set");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore value to 1
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;
    arg.val = 1;
    if (semctl(sem_id, 0, SETVAL, arg) == -1) {
        perror("Error initializing semaphore value");
        exit(EXIT_FAILURE);
    }

    // Fork the program into parent and child processes
    int pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process is waiting for lock...\n");
        P(sem_id); // Wait for lock
        printf("Child process acquired lock\n");
        sleep(3); // Do some work
        printf("Child process is releasing lock...\n");
        V(sem_id); // Release lock
        printf("Child process released lock\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process is waiting for lock...\n");
        P(sem_id); // Wait for lock
        printf("Parent process acquired lock\n");
        sleep(3); // Do some work
        printf("Parent process is releasing lock...\n");
        V(sem_id); // Release lock
        printf("Parent process released lock\n");
        wait(NULL); // Wait for child process to exit
        exit(EXIT_SUCCESS);
    }
}