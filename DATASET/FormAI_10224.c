//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {

    printf("Welcome to the Interprocess communication program!\n");

    // First, let's generate a key for our shared memory
    key_t key = ftok("shared_mem_example", 'R');
    if (key == -1) {
        perror("ftok error");
        exit(EXIT_FAILURE);
    }

    // Now, let's allocate the shared memory
    int shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget error");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to our data space
    char* shared_mem = shmat(shmid, (void *)0, 0);
    if (shared_mem == (char *)(-1)) {
        perror("shmat error");
        exit(EXIT_FAILURE);
    }

    // Write a message to the shared memory
    sprintf(shared_mem, "Hello, from the parent process!");

    // Create a child process to read the message
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child process reading from shared memory:\n");

        // Read the message from the shared memory
        printf("Read message: %s\n", shared_mem);

        // Detach the shared memory segment from our data space
        if (shmdt(shared_mem) == -1) {
            perror("shmdt error");
            exit(EXIT_FAILURE);
        }

        // Exit the child process
        exit(EXIT_SUCCESS);

    } else {
        // Wait for the child process to finish
        wait(NULL);

        // Write another message to the shared memory
        sprintf(shared_mem, "Hello, again, from the parent process!");

        // Fork another child process to read the message again
        pid_t pid2 = fork();
        if (pid2 == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            printf("Another child process reading from shared memory:\n");

            // Read the second message from the shared memory
            printf("Read message: %s\n", shared_mem);

            // Detach the shared memory segment from our data space
            if (shmdt(shared_mem) == -1) {
                perror("shmdt error");
                exit(EXIT_FAILURE);
            }

            // Exit the child process
            exit(EXIT_SUCCESS);

        }

        // Wait for the second child process to finish
        wait(NULL);

        // Detach the shared memory segment from our data space
        if (shmdt(shared_mem) == -1) {
            perror("shmdt error");
            exit(EXIT_FAILURE);
        }

        // Delete the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl error");
            exit(EXIT_FAILURE);
        }

        printf("Finished interprocess communication. Goodbye!\n");
        exit(EXIT_SUCCESS);
    }
}