//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    printf("Hello there! I am a cheerful Interprocess Communication example program.\n");

    key_t key = ftok("shmfile",65); // Generate a unique key using the file pathname and a random number

    int shmid = shmget(key,1024,0666|IPC_CREAT); // Create a shared memory segment

    char *str = (char*) shmat(shmid,(void*)0,0); // Attach the segment to our data space

    printf("\nEnter your message: ");
    fgets(str, 1024, stdin); // Get input from user and store it in the shared memory segment

    printf("\nMessage sent successfully!");

    while (*str != '*') // Keep looping until we receive the termination symbol *
    {
        sleep(1); // Wait for 1 second

        printf("\nWaiting for recipient to read the message...");

        if (*str) // If there is a message in the shared memory segment
        {
            printf("\nMessage received: %s", str);

            printf("\nEnter your reply: ");
            fgets(str, 1024, stdin); // Get input from user and store it in the shared memory segment

            printf("\nReply sent successfully!");
        }
    }

    shmdt(str); // Detach the shared memory segment

    shmctl(shmid,IPC_RMID,NULL); // Delete the shared memory segment

    printf("\nGoodbye! I hope you enjoyed our little chat.\n");

    return 0;
}