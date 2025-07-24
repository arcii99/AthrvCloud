//FormAI DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 1024

int main()
{
    key_t key;
    int shmid;
    char *shm;
    char *message = "Hello from the other side";

    key = ftok("shmfile",65);

    shmid = shmget(key, SHMSIZE, 0666|IPC_CREAT);

    shm = (char*) shmat(shmid, (void*)0, 0);

    memcpy(shm, message, strlen(message));

    printf("Message sent to shared memory: %s\n", shm);

    shmdt(shm);

    shm = (char*) shmat(shmid, (void*)0, 0);

    printf("Message read from shared memory: %s\n", shm);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}