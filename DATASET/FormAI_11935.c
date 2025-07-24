//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // generate key for shared memory
    key = ftok(".", 's');

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write to shared memory
    s = shm;
    char message[SHM_SIZE];
    printf("Enter a message: ");
    fgets(message, SHM_SIZE, stdin);
    strncpy(s, message, SHM_SIZE);

    // wait for other process to read from shared memory
    while (*shm != '*')
        sleep(1);

    // clean up
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}