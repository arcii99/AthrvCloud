//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(){
    int shmid;
    key_t key;
    char *shm;
    char *s;

    key = 1111; //unique identifier for shared memory segment

    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666); //create shared memory segment 

    if(shmid < 0){
        perror("shmget error");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0); //attach to shared memory segment

    if(shm == (char *) -1){
        perror("shmat error");
        exit(1);
    }

    //write to shared memory
    sprintf(shm, "%s", "Hello World!");

    //read from shared memory
    for(s = shm; *s != 0; s++)
        printf("%c", *s);
    printf("\n");

    *shm = '*'; //indicate end of communication

    shmdt(shm); //detach from shared memory

    shmctl(shmid, IPC_RMID, NULL); //remove shared memory segment

    return 0;
}