//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_SIZE 1000

int main() {
    // Creating a shared memory block
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,MAX_SIZE,0666|IPC_CREAT);

    if(shmid == -1) {
        printf("Error in creating shared memory block.\n");
        return 1;
    }

    // Attaching to shared memory
    char *str = (char*) shmat(shmid,(void*)0,0);
    printf("Enter the message: ");
    fgets(str,MAX_SIZE,stdin);

    // Writing to shared memory
    printf("Writing to shared memory: %s",str);

    // Detaching from shared memory
    shmdt(str);

    // Forking
    pid_t pid = fork();

    if(pid == 0) {
        // Reading from shared memory in child process
        char *child_str = (char*) shmat(shmid,(void*)0,0);
        printf("Message read from shared memory in child: %s",child_str);
        shmdt(child_str);
    } else {
        // Waiting for child process to finish
        wait(NULL);

        // Deleting the shared memory block
        shmctl(shmid,IPC_RMID,NULL);
    }

    return 0;
}