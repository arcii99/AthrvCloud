//FormAI DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to IPC example program!\n");

    int shmid;
    key_t key = 1234;
    char *data;

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        perror("shmget failed!\n");
        exit(1);
    }

    data = (char *) shmat(shmid, NULL, 0);

    if (data == (char *) -1)
    {
        perror("shmat failed!\n");
        exit(1);
    }

    printf("Enter a message to send to the second process: ");
    fgets(data, 1024, stdin);

    printf("Sending message...\n");

    sleep(1);

    printf("Receiving message...\n");

    printf("Message received from second process: %s", data);

    shmdt(data);

    shmctl(shmid, IPC_RMID, NULL);

    printf("\nExiting IPC example program...\n");

    return 0;
}