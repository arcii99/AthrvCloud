//FormAI DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    int pid;
    int shm_id;
    char *shm_ptr;
    char message[] = "Hello, World!";

    /* create shared memory segment */
    if ((shm_id = shmget(IPC_PRIVATE, SHM_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /* attach shared memory segment */
    if ((shm_ptr = shmat(shm_id, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /* fork a child process */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        /* child process */
        printf("Child process writing to shared memory...\n");
        snprintf(shm_ptr, SHM_SIZE, "%s", message);
    } else {
        /* parent process */
        wait(NULL);
        printf("Parent process reading from shared memory...\n");
        printf("Message received: %s\n", shm_ptr);
    }

    /* detach shared memory segment */
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    /* remove shared memory segment */
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}