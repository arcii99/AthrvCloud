//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
//The following program demonstrates a unique approach to interprocess communication in C, using the Donald Knuth style of programming.

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
    int status;
    key_t key = ftok(".", 'x');
    char *shm;    

    if(key == -1){
        printf("Error: Could not get key\n");
        exit(1);
    }

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if(shmid == -1){
        printf("Error: Could not get shared memory id\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    
    if(shm == (char *)-1){
        printf("Error: Could not attach shared memory\n");
        exit(1);
    }

    pid = fork(); //creating child process

    if(pid < 0){ //if fork fails
        printf("Error: Could not create child process\n");
        exit(1);
    }
    else if(pid == 0){ //if child process
        printf("Child process execution begins.\n");
        char *message = "Hello from child!";
        sprintf(shm, message);

        _exit(0);
    }
    else{ //if parent process
        printf("Parent process execution begins.\n");
        waitpid(pid, &status, 0);
        printf("Message from child process: %s\n", shm);

        if(shmdt(shm) == -1){ //detach shared memory
            printf("Error: Could not detach shared memory\n");
            exit(1);
        }

        if(shmctl(shmid, IPC_RMID, 0) == -1){ //delete shared memory
            printf("Error: Could not delete shared memory\n");
            exit(1);
        }
    }

    return 0;
}