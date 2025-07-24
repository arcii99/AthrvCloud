//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to display the semaphores
void display_semaphores(int semid, struct sembuf *s) {
    printf("\nSemaphore %d: current value=%d\n", s->sem_num, semctl(semid, s->sem_num, GETVAL, 0));
}

int main() {
    int semid, rc;
    key_t key;

    // Generate unique key
    if ((key = ftok(".", 'S')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create semaphores
    if ((semid = semget(key, 3, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // Set initial semaphore values
    if ((semctl(semid, 0, SETVAL, 1)) == -1) {
        perror("semctl");
        exit(1);
    }

    if ((semctl(semid, 1, SETVAL, 0)) == -1) {
        perror("semctl");
        exit(1);
    }

    if ((semctl(semid, 2, SETVAL, 0)) == -1) {
        perror("semctl");
        exit(1);
    }

    // Semaphore buffers
    struct sembuf s[2];

    // Child process
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        s[0].sem_num = 1;
        s[0].sem_op = -1;
        s[0].sem_flg = SEM_UNDO;

        display_semaphores(semid, &s[0]);

        // Wait for parent to signal
        rc = semop(semid, &s[0], 1);
        if (rc == -1) {
            perror("semop");
            exit(1);
        }

        printf("\nChild process: receiving message...");

        // Receive message from parent
        char message[50];
        if (read(STDIN_FILENO, message, 50) == -1) {
            perror("read");
            exit(1);
        }

        printf("\nChild process: received message: %s\n", message);

        // Signal parent
        s[0].sem_num = 2;
        s[0].sem_op = 1;
        s[0].sem_flg = SEM_UNDO;

        display_semaphores(semid, &s[0]);

        rc = semop(semid, &s[0], 1);
        if (rc == -1) {
            perror("semop");
            exit(1);
        }

        exit(0);

    } else {
        // Parent process
        s[0].sem_num = 0;
        s[0].sem_op = -1;
        s[0].sem_flg = SEM_UNDO;

        display_semaphores(semid, &s[0]);

        // Wait for child to signal
        rc = semop(semid, &s[0], 1);
        if (rc == -1) {
            perror("semop");
            exit(1);
        }

        printf("\nParent process: sending message...");

        // Send message to child
        char message[50] = "Hello from parent process";
        if(write(STDOUT_FILENO, message, strlen(message)) == -1) {
            perror("write");
            exit(1);
        }

        // Signal child
        s[0].sem_num = 1;
        s[0].sem_op = 1;
        s[0].sem_flg = SEM_UNDO;

        display_semaphores(semid, &s[0]);

        rc = semop(semid, &s[0], 1);
        if (rc == -1) {
            perror("semop");
            exit(1);
        }

        wait(NULL);

        // Remove semaphore set
        if (semctl(semid, 0, IPC_RMID) == -1) {
            perror("semctl");
            exit(1);
        }
    }

    return 0;
}