//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define SHM_SIZE 1024

// Semaphore functions
void sem_init(int sem_id, int init_val) {
    union semun {
        int val;
        struct semid_ds *buf;
        ushort *array;
    } arg;
    arg.val = init_val;
    semctl(sem_id, 0, SETVAL, arg);
}

void sem_wait(int sem_id) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    semop(sem_id, &sb, 1);
}

void sem_signal(int sem_id) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    semop(sem_id, &sb, 1);
}

int main() {
    int shmid;
    char *shmaddr;
    int semid;
    key_t key;

    // Generate a unique key for shared memory and semaphore
    key = ftok(".", 'a');

    // Create a shared memory segment for communication
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the local address space
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Create a semaphore for synchronization
    if ((semid = semget(key, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore with value 1
    sem_init(semid, 1);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Error creating child process");
        exit(1);
    }
    else if (pid == 0) {
        // This is the child process
        while (1) {
            sem_wait(semid); // Wait for access to shared memory
            printf("Child: Writing message to shared memory\n");
            sprintf(shmaddr, "Hello from child process %d", getpid());
            sem_signal(semid); // Release shared memory
            sleep(1);
        }
    }
    else {
        // This is the parent process
        while (1) {
            sem_wait(semid); // Wait for access to shared memory
            printf("Parent: Reading message from shared memory\n");
            printf("Message: %s\n", shmaddr);
            sem_signal(semid); // Release shared memory
            sleep(1);
        }
    }

    // Detach and remove shared memory segment
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    // Remove semaphore
    semctl(semid, 0, IPC_RMID);
    
    return 0;
}