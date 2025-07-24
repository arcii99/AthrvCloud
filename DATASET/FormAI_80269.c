//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shared_memory, *data;

    // Generate a key for shared memory
    key = ftok(".", 'X');

    // Create shared memory segment
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("shmget error\n");
        exit(1);
    }

    // Attach shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (char *) -1) {
        printf("shmat error\n");
        exit(1);
    }

    // Write data to shared memory and print it
    data = "Hello World";
    sprintf(shared_memory, "%s", data);
    printf("Data written to shared memory: %s\n", shared_memory);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        printf("fork error\n");
        exit(1);
    } else if (pid == 0) {
        // Child process reads data from shared memory and prints it
        printf("Child process reading data from shared memory: %s\n", shared_memory);
        exit(0);
    } else {
        // Parent process waits for child to finish
        wait(NULL);

        // Detach shared memory segment and remove it
        shmdt(shared_memory);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}