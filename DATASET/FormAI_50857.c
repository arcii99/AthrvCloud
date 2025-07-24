//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    printf("Welcome to the Interprocess Communication Example Program!\n\n");
    printf("In this program, we will create two processes - a sender and a receiver.\n");
    printf("The sender process will send a message to the receiver process using shared memory.\n");
    printf("Let's get started!\n\n");

    // create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, sizeof(char) * 100, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // attach the shared memory segment to the sender process
    char *shared_message = (char*) shmat(shmid, NULL, 0);
    if (shared_message == (char*) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // create a child process to act as the receiver
    pid_t pid = fork();
    if (pid < 0) {
        printf("Error creating child process.\n");
        exit(1);
    } else if (pid == 0) {
        // receiver process
        printf("Receiver process has been created.\n");
        sleep(1);
        printf("Message received: %s\n", shared_message);

        // detach and remove the shared memory segment
        shmdt(shared_message);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Receiver process has finished.\n");
    } else {
        // sender process
        printf("Sender process has been created.\n");
        printf("Enter a message to send: ");
        scanf("%[^\n]%*c", shared_message);

        // wait for the receiver process to finish
        wait(NULL);

        // detach and remove the shared memory segment
        shmdt(shared_message);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Sender process has finished.\n");
    }

    return 0;
}