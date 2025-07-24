//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scientific
/* 
   A Scientific Interprocess Communication Example Program 
   by Chatbot

   This program demonstrates interprocess communication between two processes using shared memory
   
   The first process initializes the shared memory segment, writes a message to it, and then waits
   for the second process to read the message.
   
   The second process attaches to the shared memory segment, reads the message, prints it to the 
   standard output, and then detaches from the shared memory segment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

#define SHMSIZE 256 /* Size of the shared memory segment */

int main(int argc, char *argv[])
{
    int shmid; /* Shared memory segment ID */
    char *shmaddr; /* Pointer to the shared memory segment */
    key_t key; /* Shared memory key */
    int pid; /* Process ID */
    char message[] = "Hello from Process 1!"; /* Message to be written to shared memory */
    
    /* Generate a unique key for the shared memory segment */
    key = ftok("/tmp", 'S');
    
    /* Create the shared memory segment */
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
    
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    /* Attach to the shared memory segment */
    shmaddr = shmat(shmid, NULL, 0);
    
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    /* Write the message to the shared memory segment */
    sprintf(shmaddr, "%s", message);
    
    /* Fork a second process */
    pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    /* Child process reads the message from the shared memory segment */
    else if (pid == 0) {
        char buffer[SHMSIZE];
        
        /* Attach to the shared memory segment */
        shmaddr = shmat(shmid, NULL, 0);
        
        if (shmaddr == (char *) -1) {
            perror("shmat");
            exit(1);
        }
        
        /* Read the message from the shared memory segment */
        sprintf(buffer, "%s", shmaddr);
        
        /* Print the message to the standard output */
        printf("Message received from Process 1: %s\n", buffer);
        
        /* Detach from the shared memory segment */
        shmdt(shmaddr);
        
        exit(0);
    }
    
    /* Parent process waits for the child process to complete */
    else {
        wait(NULL);
        
        /* Detach from the shared memory segment */
        shmdt(shmaddr);
        
        /* Remove the shared memory segment */
        shmctl(shmid, IPC_RMID, NULL);
        
        exit(0);
    }
}