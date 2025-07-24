//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 100

int main()
{
    pid_t pid;
    int shmid;
    char *shm, *s;

    // Creating shared memory.
    if((shmid = shmget(IPC_PRIVATE, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attaching the shared memory segment.
    if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Writing a message to the shared memory segment.
    sprintf(shm, "Hello, world!");

    // Forking a child process.
    if((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) { // Child process.
        // Reading the message from the shared memory segment.
        s = shm;
        s += 13; // Move the pointer 13 bytes to skip "Hello, world!".

        printf("%s", s); // Printing the message.

        // Detaching the shared memory segment.
        if(shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Removing the shared memory segment.
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        _exit(0);
    }
    else { // Parent process.
        wait(NULL); // Waiting for the child process to complete.

        // Detaching the shared memory segment.
        if(shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Removing the shared memory segment.
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}