//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // Shared memory size

int main() {
    int pid, shmid, ret;
    char *data;
    key_t key = 123;  // Shared memory key

    // Creating shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attaching shared memory segment
    data = shmat(shmid, NULL, 0);
    if (data == (char *) -1) {
        perror("shmat");
        return 1;
    }

    // Writing data to shared memory
    sprintf(data, "Hello, World!");

    // Creating child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {  // Child process
        printf("Child process reading data from shared memory...\n");

        // Reading data from shared memory
        printf("Data read from shared memory: %s\n", data);

        // Detaching shared memory segment
        ret = shmdt(data);
        if (ret < 0) {
            perror("shmdt");
        }

        // Terminating child process
        exit(0);
    } else {  // Parent process
        // Waiting for child process to terminate
        wait(NULL);

        // Detaching and deleting shared memory segment
        ret = shmdt(data);
        if (ret < 0) {
            perror("shmdt");
        }
        ret = shmctl(shmid, IPC_RMID, NULL);
        if (ret < 0) {
            perror("shmctl");
        }
    }

    return 0;
}