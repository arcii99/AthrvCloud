//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    printf("Welcome to the Happy Interprocess Communication Program!\n");
    printf("Let's create a shared memory segment...\n");

    // Get a unique key for the shared memory segment
    key_t key = ftok("happy_ipc_program", 'R');

    // Create the shared memory segment with a size of 1024 bytes
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);

    // Attach the shared memory segment to the current process
    char *shared_memory = (char*) shmat(shmid, (void*)0, 0);

    // Let's write some happy data to the shared memory segment
    sprintf(shared_memory, "Hello World!");

    printf("Shared memory segment created successfully!\n");

    // Now let's fork a child process to read the data from the shared memory segment
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process created successfully!\n");

        // Attach the shared memory segment to the child process
        char *child_memory = (char*) shmat(shmid, (void*)0, 0);

        printf("Child process read data from shared memory: %s\n", child_memory);

        // Detach the shared memory segment from the child process
        shmdt(child_memory);
        printf("Child process detached shared memory successfully!\n");
    } else if (pid > 0) {
        // Parent process
        printf("Parent process waiting for child process...\n");

        wait(NULL);

        printf("Child process finished successfully!\n");

        // Detach the shared memory segment from the parent process
        shmdt(shared_memory);
        printf("Parent process detached shared memory successfully!\n");

        // Delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
        printf("Shared memory segment deleted successfully!\n");
    } else {
        // Error forking a new process
        printf("Error forking a new process!\n");
        exit(1);
    }

    printf("Program completed successfully! Have a happy day!\n");
    return 0;
}