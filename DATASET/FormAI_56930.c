//FormAI DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHARED_MEMORY_KEY 2019
#define SHARED_MEMORY_SIZE 1024

int main() {
    int shmid;
    void *shmaddr;

    //Create shared memory
    shmid = shmget(SHARED_MEMORY_KEY, SHARED_MEMORY_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget error");
        exit(EXIT_FAILURE);
    }

    //Attach to shared memory
    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (void *) -1) {
        perror("shmat error");
        exit(EXIT_FAILURE);
    }

    //Write a message to shared memory
    sprintf(shmaddr, "Hello World from Process 1!");

    //Detach from shared memory
    shmdt(shmaddr);

    //Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        //Process 2
        void *shmaddr2;

        //Attach to shared memory
        shmaddr2 = shmat(shmid, NULL, 0);

        if (shmaddr2 == (void *) -1) {
            perror("shmat error");
            exit(EXIT_FAILURE);
        }

        //Read the message from shared memory
        printf("Message from Process 1: %s\n", (char *) shmaddr2);

        //Detach from shared memory
        shmdt(shmaddr2);

        //Exit child process
        exit(EXIT_SUCCESS);
    } else {
        //Process 1
        wait(NULL);

        //Detach and remove shared memory
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);

        //Exit parent process
        exit(EXIT_SUCCESS);
    }
}