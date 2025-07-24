//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 100
#define KEY 1234

int main()
{
    int shmid;
    char *shm;
    
    // Create shared memory segment
    shmid = shmget(KEY, SHMSIZE, IPC_CREAT | 0666);
    if(shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if(shm == (char*) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Write a message to the shared memory
    sprintf(shm, "Hello World!");
    
    printf("Message written to shared memory: %s\n", shm);
    
    // Detach shared memory segment
    shmdt(shm);
    
    // Wait for child process to finish
    wait(NULL);
    
    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}