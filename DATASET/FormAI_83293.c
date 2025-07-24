//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
/* A unique example of Interprocess communication in C */
/* This program demonstrates communication between a parent process and multiple child processes using shared memory and semaphores */
/* By IrregularProgrammer */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define NUM_CHILD_PROCESSES 5 // Define the number of child processes
#define SHM_SIZE 256 // Define the size of the shared memory segment

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};

void sem_lock(int sem_id)
{
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(sem_id, &sb, 1);
}

void sem_unlock(int sem_id)
{
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = SEM_UNDO;
    semop(sem_id, &sb, 1);
}

int main()
{
    int shmid, semid, i;
    char *shm_ptr;
    union semun sem_val;

    // Create the shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory segment
    shm_ptr = (char *) shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Create the semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semid == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore value to 1
    sem_val.val = 1;
    if (semctl(semid, 0, SETVAL, sem_val) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    // Fork multiple child processes
    for (i = 0; i < NUM_CHILD_PROCESSES; i++) {
        if (fork() == 0) {
            printf("Child process %d created\n", getpid());

            // Attach to the shared memory segment
            shm_ptr = (char *) shmat(shmid, NULL, 0);
            if (shm_ptr == (char *) -1) {
                perror("shmat");
                exit(EXIT_FAILURE);
            }

            // Attach to the semaphore
            semid = semget(IPC_PRIVATE, 1, 0666);
            if (semid == -1) {
                perror("semget");
                exit(EXIT_FAILURE);
            }

            // Loop to execute semaphored code iteratively
            for (int j = 0; j < 5; j++) {
                sem_lock(semid);

                // Read from the shared memory segment
                printf("Child process %d reading from shared memory: %s\n", getpid(), shm_ptr);

                // Write to the shared memory segment
                sprintf(shm_ptr, "Hello from %d", getpid());
                printf("Child process %d writing to shared memory: %s\n", getpid(), shm_ptr);

                sem_unlock(semid);
            }

            // Detach from the shared memory segment
            if (shmdt(shm_ptr) == -1) {
                perror("shmdt");
                exit(EXIT_FAILURE);
            }

            exit(EXIT_SUCCESS);
        }
    }

    // Parent process waits for all child processes to complete
    for (i = 0; i < NUM_CHILD_PROCESSES; i++) {
        wait(NULL);
    }

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    // Remove the semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}