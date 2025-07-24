//FormAI DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {

    // create shared memory
    int shmid;
    char *shmaddr;
    key_t key = 1234;
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach to shared memory
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write to shared memory
    sprintf(shmaddr, "Welcome to the Post-Apocalyptic World!");

    // print message from shared memory
    printf("%s\n", shmaddr);

    // fork child process
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process reads from shared memory
        printf("Child process reading from shared memory...\n");
        printf("Message from shared memory: %s\n", shmaddr);
        sprintf(shmaddr, "The end is near!");
        printf("Child process wrote to shared memory: %s\n", shmaddr);
        exit(0);
    } else {
        // parent process waits for child to finish
        printf("Parent process waiting for child...\n");
        waitpid(pid, NULL, 0);
        printf("Child process finished.\n");

        // print updated message from shared memory
        printf("Updated message from shared memory: %s\n", shmaddr);
    }

    // detach and destroy shared memory
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}