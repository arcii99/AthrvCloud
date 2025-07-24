//FormAI DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MSG_SIZE 100

int main() {
    int shmid;
    key_t key;
    char *shm;
    char message[MSG_SIZE];
    pid_t pid;
    
    printf("Welcome to the Interprocess Communication Program!\n");
    
    printf("First, let's create the shared memory segment.\n");
    key = ftok("hello.c", 'R');
    shmid = shmget(key, MSG_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Shared memory segment created successfully! Let's attach it to our process.\n");
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Shared memory segment attached to our process!\n");
    printf("Time to fork our process.\n");
    pid = fork();
    
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        printf("Child process reporting for duty!\n");
        printf("Enter a message to send to the parent process:\n");
        fgets(message, MSG_SIZE, stdin);
        printf("Child process sending message to parent process...\n");
        sprintf(shm, "%s", message);
        printf("Message sent successfully!\n");
    } else { // Parent process
        printf("Parent process reporting for duty!\n");
        sleep(1);
        printf("Parent process receiving message from child process...\n");
        printf("Message: %s", shm);
    }
    
    printf("Now let's detach our shared memory segment...\n");
    if (shmdt(shm) == -1) {
        perror("shmdt failed");
    }
    
    printf("Shared memory segment detached successfully!\n");
    
    printf("Lastly, let's delete our shared memory segment...\n");
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl failed");
    }
    
    printf("Shared memory segment deleted successfully!\n");
    
    return 0;
}