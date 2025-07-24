//FormAI DATASET v1.0 Category: Interprocess communication ; Style: standalone
/*
 * This is an example program that demonstrates inter-process communication
 * using shared memory. The program creates a shared memory segment, forks a
 * child process, communicates with the child process through the shared
 * memory, and finally releases the shared memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234       // Shared memory key
#define SHM_SIZE 1024         // Shared memory size

int main() {
    int status;
    int shm_id;
    void *shm_addr;

    // Create the shared memory segment
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);

    if (shm_id == -1) {
        perror("Error creating shared memory");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory segment
    shm_addr = shmat(shm_id, NULL, 0);

    if (shm_addr == (void *) -1) {
        perror("Error attaching to shared memory");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("Error forking child process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // child process
        char *message = "Hello from child process!";
        printf("Child process starts writing to shared memory\n");
        sprintf(shm_addr, "%s", message);
        printf("Child process writes \"%s\" to shared memory\n", message);
        exit(EXIT_SUCCESS);
    } else {         // parent process
        printf("Parent process waits for child process to finish writing to shared memory\n");
        waitpid(-1, &status, 0);
        printf("Parent process starts reading from shared memory\n");
        printf("Parent process reads \"%s\" from shared memory\n", (char *) shm_addr);

        // Detach from the shared memory segment
        if (shmdt(shm_addr) == -1) {
            perror("Error detaching from shared memory");
            exit(EXIT_FAILURE);
        }

        // Release the shared memory segment
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("Error releasing shared memory");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

    return 0;
}