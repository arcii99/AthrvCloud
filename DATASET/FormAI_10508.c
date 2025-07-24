//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    int shmid;
    char *shm;
    char message[SHM_SIZE];

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*)-1)
    {
        perror("shmat");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0) // Child process
    {
        printf("Enter message for parent process: ");
        fgets(message, SHM_SIZE, stdin);

        // Copy message to shared memory segment
        sprintf(shm, "%s", message);
        printf("Message sent to parent process: %s\n", shm);

        exit(0);
    }
    else // Parent process
    {
        wait(NULL);

        // Read message from shared memory segment
        printf("Message received from child process: %s\n", shm);

        // Detach shared memory segment
        shmdt(shm);

        // Delete shared memory segment
        shmctl(shmid, IPC_RMID, 0);
    }

    return 0;
}