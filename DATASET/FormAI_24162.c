//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<error.h>
#include<string.h>

int main()
{
    // Create shared memory object
    int shmid;
    int key = ftok("shmfile",65);
    shmid = shmget(key,1024,0666|IPC_CREAT);

    // Attach to shared memory object
    char *str = (char*) shmat(shmid,(void*)0,0);

    // Write to shared memory object
    sprintf(str,"Hello World!");
    printf("Writer Process: Wrote \"%s\" to shared memory.\n", str);

    // Detach from shared memory object
    shmdt(str);

    // Fork child process
    int pid = fork();

    if(pid == 0) // Child process reads from shared memory object
    {
        sleep(5); // Wait for writer process to finish writing to shared memory
        printf("\nReader Process: Reading from shared memory...\n");
        char *read_str = (char*) shmat(shmid,(void*)0,0);
        printf("Reader Process: Read \"%s\" from shared memory.\n", read_str);
        shmdt(read_str);
        exit(0);
    }
    else // Parent process waits for child process to finish
    {
        wait(NULL);
        // Detach from shared memory object
        shmdt(str);

        // Deallocate shared memory object
        shmctl(shmid,IPC_RMID,NULL);
        printf("\nWriter Process: Deleted shared memory object.\n");
    }

    return 0;
}