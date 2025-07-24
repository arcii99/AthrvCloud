//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
    key_t key = ftok("shmfile",65);  // generate unique key
    int shmid = shmget(key,1024,0666|IPC_CREAT); // create shared memory segment

    char *str = (char*) shmat(shmid,(void*)0,0); // attach shared memory segment to process
    
    printf("Enter string: ");
    fgets(str, 100, stdin); // read input string

    printf("String entered: %s",str); // display input string

    shmdt(str); // detach shared memory segment
    
    // create new process
    pid_t pid = fork();
    if(pid == -1){
        printf("Error in forking");
        return 1;
    }
    else if(pid == 0){ //child process
        printf("Child process accessing shared memory: %s",str); // access shared memory segment
        shmdt(str); //detach shared memory segment
    }
    else{ // parent process
        wait(NULL); // wait for child process to complete
        printf("Parent process completed\n");
    }

    return 0;
}