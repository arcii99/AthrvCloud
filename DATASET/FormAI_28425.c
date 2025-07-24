//FormAI DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  //Size of shared memory
#define KEY 5678      //Key for shared memory segment

int main(){

    //Shared memory segment ID
    int shm_id;

    //Shared memory pointer
    char *shm_ptr;

    //Create shared memory segment
    shm_id = shmget(KEY, SHM_SIZE, IPC_CREAT | 0666);

    if(shm_id < 0){
        perror("shmget error\n");
        exit(1);
    }

    //Attach to shared memory segment
    shm_ptr = shmat(shm_id, NULL, 0);
    if(shm_ptr == (char *)-1){
        perror("shmat error\n");
        exit(1);
    }

    //Write message to shared memory segment
    sprintf(shm_ptr, "Hello, World!");

    //Detach from shared memory segment
    shmdt(shm_ptr);

    //Wait for other process to read the message
    sleep(2);

    //Attach to shared memory segment again
    shm_ptr = shmat(shm_id, NULL, 0);
    if(shm_ptr == (char *)-1){
        perror("shmat error\n");
        exit(1);
    }

    //Read message from shared memory segment
    printf("Message: %s\n", shm_ptr);

    //Detach from shared memory segment
    shmdt(shm_ptr);

    //Delete shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}