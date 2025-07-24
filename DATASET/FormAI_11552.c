//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
/*
* interprocess.c
* A unique C Interprocess communication program
* By [Your Name]
* 
* This program demonstrates how to achieve Interprocess Communication (IPC)
* using shared memory and semaphores in C programming language.
*
* Usage: compile and run the program on two different terminals
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#define SEM_KEY 0x1234    // semaphore key
#define SHM_KEY 0x5678    // shared memory key
#define SIZE 256          // size of shared memory
#define PROCESS_A_ID 0    // process A identifier
#define PROCESS_B_ID 1    // process B identifier

union semun {
    int val;             // Value for SETVAL
    struct semid_ds *buf;    // Buffer for IPC_STAT, IPC_SET
    unsigned short *array;  // Array for GETALL, SETALL
    struct seminfo *__buf;  // Buffer for IPC_INFO
};

int main() {
    int semid, shmid, pid;
    char *buffer;
    union semun arg;
    struct sembuf sb = {0, -1, 0};  // struct for sembuf
    struct sembuf sc = {0, 1, 0};   // struct for sembuf

    // Create the semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore to 1
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    // Create the shared memory
    shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory
    buffer = (char *) shmat(shmid, NULL, 0);
    if (buffer == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Get Process ID
    pid = getpid();

    // Execute Process A 
    if (pid == PROCESS_A_ID) {
        printf("Process A is started\n");

        // Write to the shared memory
        snprintf(buffer, SIZE, "This is a test message from Process A.");

        // Wait for Process B
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(EXIT_FAILURE);
        }

        // Read from the shared memory
        printf("Process A received message: %s\n", buffer);
    }

    // Execute Process B
    else if (pid == PROCESS_B_ID) {
        printf("Process B is started\n");

        // Wait for Process A
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(EXIT_FAILURE);
        }

        // Read from the shared memory
        printf("Process B received message: %s\n", buffer);

        // Write to the shared memory
        snprintf(buffer, SIZE, "This is a test message from Process B.");

        // Signal to Process A
        if (semop(semid, &sc, 1) == -1) {
            perror("semop");
            exit(EXIT_FAILURE);
        }
    }

    // Detach the shared memory
    if (shmdt(buffer) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove the shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    // Remove the semaphore
    if (semctl(semid, 0, IPC_RMID, arg) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    printf("Process %c is done\n", pid == PROCESS_A_ID ? 'A' : 'B');

    return 0;
}