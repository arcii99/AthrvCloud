//FormAI DATASET v1.0 Category: Interprocess communication ; Style: systematic
// A C Program for Interprocess communication between two processes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

//Defining the shared memory key
#define SHM_KEY 0x1234

//Structure of data stored in shared memory
struct shared_memory_data {
    char message[100];
};

int main() {

    //Initializing all the variables used for IPC
    int shmid;
    key_t key;
    struct shared_memory_data *shared_mem_ptr;
    pid_t pid;

    //Creating a shared memory segment
    key = SHM_KEY;
    shmid = shmget(key, sizeof(struct shared_memory_data), 0666 | IPC_CREAT);
    if(shmid < 0) {
        perror("shmget");
        exit(1);
    }

    //Attaching the shared memory segment
    shared_mem_ptr = shmat(shmid, NULL, 0);
    if(shared_mem_ptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    //Forking a child process
    pid = fork();
    if(pid < 0) {
        perror("fork");
        exit(1);
    }

    //Child Process
    else if(pid == 0) {

        //Reading data from shared memory
        printf("[CHILD] Reading data from shared memory...\n");
        printf("[CHILD] Message : %s\n", shared_mem_ptr->message);

        //Modifying the shared memory data
        printf("[CHILD] Modifying the shared memory data...\n");
        sprintf(shared_mem_ptr->message, "Hello, I am your child!");

        //Exiting the child process
        printf("[CHILD] Exiting the child process...\n");
        exit(0);
    }

    //Parent Process
    else {
        //Writing data to shared memory
        printf("[PARENT] Writing data to shared memory...\n");
        sprintf(shared_mem_ptr->message, "Hello, I am your parent!");

        //Waiting for the child process to finish
        printf("[PARENT] Waiting for child process to finish...\n");
        wait(NULL);

        //Reading data from shared memory
        printf("[PARENT] Reading data from shared memory...\n");
        printf("[PARENT] Message : %s\n", shared_mem_ptr->message);

        //Detaching shared memory
        printf("[PARENT] Detaching shared memory...\n");
        shmdt(shared_mem_ptr);
        printf("[PARENT] Exiting the parent process...\n");
    }

    //Deleting shared memory
    printf("[CLEANING UP] Deleting shared memory...\n");
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}