//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 1024 /* shared memory size */

int main() {
    key_t key = 1234; /* shared memory key */
    int shmid;
    char *data, *ptr;

    /* create shared memory segment */
    if ((shmid = shmget(key, SHMSIZE, 0666 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    /* attach shared memory segment */
    if ((data = shmat(shmid, NULL, 0)) == (char*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    /* send message to parent process */
    ptr = data;
    sprintf(ptr, "Hello parent process!");

    /* detach shared memory segment */
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}