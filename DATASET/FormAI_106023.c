//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
// C Interprocess Communication Example Program
// This program demonstrates interprocess communication between two processes
// using shared memory and semaphores in C language.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

int main() {
    key_t key;
    int shm_id, sem_id;
    char str[SHM_SIZE];
    struct sembuf sem_op;

    // generate a unique key
    if ((key = ftok(".", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // create shared memory segment
    if ((shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment
    char *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // create semaphore
    if ((sem_id = semget(key, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // initialize semaphore to 1
    union semun init_sem;
    init_sem.val = 1;
    if (semctl(sem_id, 0, SETVAL, init_sem) == -1) {
        perror("semctl");
        exit(1);
    }

    // write to shared memory
    printf("Enter a message: ");
    fgets(str, SHM_SIZE, stdin);
    sprintf(shm_ptr, "%s", str);

    // acquire semaphore
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // read from shared memory
    printf("Received message: %s", shm_ptr);

    // release semaphore
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete semaphore
    if (semctl(sem_id, 0, IPC_RMID, 0) == -1) {
        perror("semctl");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shm_id, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}