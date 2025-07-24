//FormAI DATASET v1.0 Category: Interprocess communication ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<string.h>

#define SIZE 1024

int main(){

    pid_t pid;

    //Shared Memory
    key_t key = ftok("/tmp", 'a');
    int shmid = shmget(key, SIZE, IPC_CREAT|0666);
    char *data;
    data = (char*)shmat(shmid, NULL, 0);

    //Fork Child Process
    pid = fork();

    if(pid < 0){
        perror("Fork Failed");
        return 1;
    }
    else if(pid == 0){ //Child Process
        sprintf(data, "Message from Child Process!");
        printf("Child Process: Message sent to Parent\n");
    }
    else{ //Parent Process
        wait(NULL);
        printf("Parent Process: Message received from Child: %s\n", data);

        //Detach and Free Shared Memory
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}