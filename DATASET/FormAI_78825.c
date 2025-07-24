//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

void mind_bending(void) {
    printf("The mind-bending program has begun...\n\n");
    sleep(2);
    printf("Welcome to the world of interprocess communication!\n");
    sleep(2);
    printf("We will be using shared memory to pass data between processes.\n\n");
    sleep(2);
    
    printf("Initializing shared memory...\n");
    int shmid;
    char *shm, *s;
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    printf("Attaching shared memory...\n");
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Writing to shared memory...\n");
    s = shm;
    sprintf(s, "%s", "Hello world!");

    printf("Forking child process...\n");
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0) {
        /* Child process */
        printf("Child process reading from shared memory...\n");
        s = shm;
        s += 12; /* Move pointer to skip "Hello world!" */
        printf("Child process received message: %s\n", s);
        
        printf("Child process writing to shared memory...\n");
        sprintf(s, "%s", "Hello from child process!");
        printf("Child process done writing to shared memory.\n");
        
        printf("Child process detaching shared memory...\n");
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        
        printf("Child process exiting...\n");
        exit(0);
    } else {
        /* Parent process */
        printf("Parent process waiting for child to finish...\n");
        wait(NULL); /* Wait for child process to finish */
        
        printf("Parent process reading from shared memory...\n");
        s = shm;
        printf("Parent process received message: %s\n", s);
        
        printf("Parent process detaching shared memory...\n");
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        printf("Parent process exiting...\n");
        exit(0);
    }
}

int main(void) {
    mind_bending();
    return 0;
}