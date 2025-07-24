//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_SIZE 1000

int main() {
    int shmid;
    key_t key;
    char* shared_data;
    pid_t pid;

    // Generate unique key for shared memory segment
    key = ftok("shmfile",65);

    // Allocate shared memory
    shmid = shmget(key, MAX_SIZE, 0666|IPC_CREAT);

    // Attach shared memory to process
    shared_data = (char*)shmat(shmid, NULL, 0);

    // Display shared memory segment ID
    printf("Shared Memory Segment ID: %d\n", shmid);

    // Fork new process
    pid = fork();

    if (pid == 0) {
        printf("[Child Process] Enter Data: ");
        fgets(shared_data, MAX_SIZE, stdin);
        printf("[Child Process] Data Written to Shared Memory: %s", shared_data);
    } else if (pid > 0) {
        wait(NULL);
        printf("[Parent Process] Data Read from Shared Memory: %s", shared_data);
    }

    // Detach shared memory segment from process
    shmdt(shared_data);

    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}