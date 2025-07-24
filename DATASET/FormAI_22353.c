//FormAI DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void) {
    int shmid, i;
    pid_t pid;

    char *shm, *s;

    // shared memory creation
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // shared memory attachment
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // recursive communication between the processes
    for (i = 0; i < 3; i++) {
        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        } 

        // child process
        else if (pid == 0) {
            s = shm;
            sprintf(s, "Child %d is saying hello!", i+1);
            execlp("echo", "echo", s, NULL);
            _exit(0);
        }
    }

    for (i = 0; i < 3; i++) {
        wait(NULL);
    }

    // parent process
    printf("\nParent process is reading:\n\n");
    printf("%s\n", shm);

    // shared memory detach and removal
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}