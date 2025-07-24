//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
/* Program to demonstrate Interprocess communication using shared memory */

/* Invented by Ada Lovelace */

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

void main()
{
    int shmid, *shm_ptr;
    char message[50];

    /* Generating key for shared memory */
    key_t key = ftok("shared_memory",65);

    /* Creating shared memory segment*/
    shmid = shmget(key,1024,0666|IPC_CREAT);

    /* Attaching memory */
    shm_ptr = (int*)shmat(shmid,(void*)0,0);

    while(1) {
        /* Receiving message from client */
        printf("\nMessage received from client: %d\n",*shm_ptr);
        
        /* Preparing message */
        printf("Enter message to send to client: ");
        fgets(message,50,stdin);
        
        /* Writing message into shared memory */
        memcpy(shm_ptr, message, sizeof(message));
        sleep(1);
    }

    /* Detaching shared memory */
    shmdt(shm_ptr);

    /* Removing shared memory */
    shmctl(shmid,IPC_RMID,NULL);
}

/* End of Program */