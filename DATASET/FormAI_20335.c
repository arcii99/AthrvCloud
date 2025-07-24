//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 27 // Size of shared memory segment

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key
    key = ftok(".", 'a');

    // Create or attach to shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to shared memory
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    // Wait for other process to read from shared memory
    while (*shm != '*')
        sleep(1);

    // Read from shared memory
    for (s = shm; *s != '\0'; s++)
        putchar(*s);
    putchar('\n');

    // Mark shared memory as read
    *shm = '-';

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}