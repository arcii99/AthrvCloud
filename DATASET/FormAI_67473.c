//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSIZE 1024

int main() {
    int shmid;
    char *shm, *s;
    key_t key = 5678;

    if ((shmid = shmget(key, BUFSIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;

    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }

    *s = '\0';

    while (*shm != '*') {
        sleep(1);
    }

    s = shm;

    for (char c = 'A'; c <= 'Z'; c++) {
        *s++ = c;
    }

    *s = '\0';

    exit(0);
}