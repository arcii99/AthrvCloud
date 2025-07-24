//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSIZE 27 //Shared memory size

int main(){
    int shmid; //Shared memory id
    key_t key; //Key value

    char *shm, *s; //Pointers to shared memory

    key = 5678; //Assigning a unique key value
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666); //Creating shared memory segment

    if(shmid < 0){ //Error checking
        perror("shmget");
        return 1;
    }

    shm = shmat(shmid, NULL, 0); //Attaching shared memory segment to data space

    if(shm == (char *) -1){ //Error checking
        perror("shmat");
        return 1;
    }

    s = shm; //Initializing pointer

    for(char c = 'a'; c <= 'z'; c++){ //Writing to shared memory segment
        *s++ = c;
    }

    *s = '\0'; //Marking end of string

    while(*shm != '*'){ //Reading from shared memory segment
        sleep(1);
    }

    printf("Message received: %s\n", shm); //Displaying message

    *shm = '#'; //Writing to shared memory segment

    return 0;
}