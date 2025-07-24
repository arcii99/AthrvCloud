//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main(void) {
    pid_t pid;
    int shmid;
    key_t key;
    char *data;
    int status;

    /* Generate a unique key for the shared memory segment */
    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* Create the shared memory segment with read and write permission */
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    /* Attach the shared memory segment to our data space */
    if ((data = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    /* Write some data to the shared memory */
    sprintf(data, "Hello World!");

    /* Create a child process to read the data from the shared memory segment */
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) { /* Child process */
        /* Read the data from the shared memory segment */
        printf("Child PID: %d\n", getpid());
        printf("Message from parent: %s\n", data);

        /* Detach the shared memory segment from our data space */
        if (shmdt(data) == -1) {
            perror("shmdt");
            exit(1);
        }

        /* Terminate the child process */
        exit(0);
    }
    else { /* Parent process */
        /* Wait for the child process to finish */
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(1);
        }

        /* Print the exit status of the child process */
        printf("Child process exited with status %d\n", WEXITSTATUS(status));

        /* Detach the shared memory segment from our data space */
        if (shmdt(data) == -1) {
            perror("shmdt");
            exit(1);
        }

        /* Remove the shared memory segment */
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}