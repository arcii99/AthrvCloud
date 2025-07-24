//FormAI DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

/* This is an example program to demonstrate interprocess communication using shared memory in C */

int main()
{
    // Creating a shared memory segment
    int shmid;
    char *shmaddr;
    key_t key = 1234;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Writing to shared memory
    sprintf(shmaddr, "Hello world!");

    // Forking a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // This is the child process
        printf("Child reading from shared memory: %s\n", shmaddr);
        exit(0);
    } else {
        // This is the parent process
        printf("Parent waiting for child to finish...\n");
        wait(NULL);
        printf("Parent finished waiting.\n");
    }

    // Detaching from shared memory
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Deleting shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}