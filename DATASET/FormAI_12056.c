//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    key = 1234;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Enter a message: ");
    fgets(shm, SHM_SIZE, stdin);

    s = shm;

    while (*s != '\0') {
        putchar(*s);
        s++;
    }
    putchar('\n');

    *shm = '*';

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}