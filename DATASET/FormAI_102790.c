//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    char *shmaddr;
    char *s;

    // Create a shared memory with key value 1234
    if ((shmid = shmget(1234, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Attach the shared memory to the current process
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory
    char message[] = "Hello, world!";
    strcpy(shmaddr, message);

    // Read from the shared memory
    s = shmaddr;
    while (*s != '\0') {
        putchar(*s);
        s++;
    }
    putchar('\n');

    // Detach the shared memory from the current process
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}