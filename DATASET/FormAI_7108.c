//FormAI DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

#define SHM_SIZE 1024

typedef struct {
    pid_t pid;
    char message[SHM_SIZE];
} shared_data;

void signal_handler(int signum) {
    printf("Interrupt signal received. Exiting.\n");
    exit(1);
}

int main() {
    
    int shmid;
    shared_data *shared_memory;
    key_t key = 1234;

    // create shared memory segment
    if ((shmid = shmget(key, sizeof(shared_data), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment
    if ((shared_memory = shmat(shmid, NULL, 0)) == (shared_data *) -1) {
        perror("shmat");
        exit(1);
    }

    // register signal handler
    signal(SIGINT, signal_handler);

    // fork child process
    pid_t pid = fork();

    if (pid == -1) { // fork error
        perror("fork");
        exit(1);
    }

    else if (pid == 0) { // child process
        while (1) {
            printf("Enter a message to send to parent process:\n");
            fgets(shared_memory->message, SHM_SIZE, stdin);
            shared_memory->pid = getpid();
        }
    }

    else { // parent process
        while (1) {
            if (shared_memory->pid != pid) {
                printf("Message received from child process (PID %d): %s", shared_memory->pid, shared_memory->message);
            }
            shared_memory->pid = 0;
            memset(shared_memory->message, 0, SHM_SIZE);
        }
    }

    // detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}