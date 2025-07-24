//FormAI DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key = 5678;
    char *shared_memory, *parent_message, *child_message;

    // Creating shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attaching the shared memory segment
    if ((shared_memory = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Creating child process
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        exit(1);
    }

    if (pid == 0) { // Child process
        child_message = "Hello, Parent Process!";
        parent_message = shared_memory;
        printf("Child process starting...\n");
        printf("Child sending message to parent.\n");
        sprintf(parent_message, "%s", child_message);
        exit(0);
    }

    else { // Parent process
        parent_message = "Hello, Child Process!";
        printf("Parent process starting...\n");
        printf("Parent sending message to child.\n");
        child_message = shared_memory + sizeof(parent_message);
        sprintf(child_message, "%s", parent_message);
        wait(NULL);
        printf("Parent received message from child: %s\n", shared_memory);
        
        // Detaching the shared memory segment
        shmdt(shared_memory);

        // Removing the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }
    
    return 0;
}