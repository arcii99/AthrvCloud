//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;

    for (c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    while (*shm != '*') {
        sleep(1);
    }

    return 0;
}