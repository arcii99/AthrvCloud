//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    // key generation for shared memory
    key_t key = ftok("shmfile",65);

    // shared memory creation
    int shmid = shmget(key,1024,0666|IPC_CREAT);

    // attaching shared memory to the process
    char *str = (char*) shmat(shmid,(void*)0,0);

    // reading from shared memory
    printf("Data read from memory: %s\n",str);

    // writing to shared memory
    printf("Enter data to be written into memory: ");
    scanf("%[^\n]", str);

    printf("Data written to memory: %s\n",str);

    // detaching shared memory from the process
    shmdt(str);

    // removing shared memory
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}