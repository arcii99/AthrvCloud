//FormAI DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    char *shm, *s;
    key_t key = 1234;  /* any value, must be the same for both processes */

    /* create shared memory segment */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /* attach shared memory segment to process */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /* write to shared memory segment */
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    /* wait for other process to read from shared memory segment */
    while (*shm != '*')
        sleep(1);

    /* detach shared memory segment from process */
    shmdt(shm);

    /* remove shared memory segment */
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}