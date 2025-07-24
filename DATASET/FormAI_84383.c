//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key;
    char *shared_memory, *message;
    
    // create a shared memory segment
    key = 123456;
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    
    // attach shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    
    // read message from shared memory
    message = shared_memory;
    printf("Message read from shared memory: %s\n", message);
    
    // write message to shared memory
    sprintf(shared_memory, "Hello from the other side!");
    printf("Message written to shared memory: %s\n", shared_memory);
    
    // detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
    
    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}