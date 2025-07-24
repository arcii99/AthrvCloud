//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#define MSG_SIZE 50

// Declare the message structure
struct message {
    long mtype;
    char mtext[MSG_SIZE];
};

// Declare the message queue ids
int mqid1, mqid2;

// Declare the signal handler for SIGINT
void handle_sigint(int sig) {
    // Remove the message queues
    msgctl(mqid1, IPC_RMID, 0);
    msgctl(mqid2, IPC_RMID, 0);
    
    // Print goodbye message
    printf("\nGoodbye! :)\n");

    // Exit the program
    exit(0);
}

// Declare the main function
int main() {
    // Declare variables
    struct message msg;
    pid_t child;

    // Create the message queues
    mqid1 = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    mqid2 = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    // Check if the message queues were created successfully
    if (mqid1 == -1 || mqid2 == -1) {
        printf("Failed to create message queues\n");
        exit(1);
    }

    // Fork a child process
    child = fork();

    // Check if the fork was successful
    if (child == -1) {
        printf("Failed to fork process\n");
        exit(1);
    }

    // Child process
    if (child == 0) {
        // Declare variables
        struct message msg1, msg2;

        // Print child process message
        printf("I am the child process (PID: %d)\n", getpid());

        // Receive message from parent process
        msgrcv(mqid1, &msg1, sizeof(msg1), 1, 0);

        // Print received message
        printf("Child process received message: %s\n", msg1.mtext);

        // Send response to parent process
        msg2.mtype = 2;
        snprintf(msg2.mtext, MSG_SIZE, "Hello Parent! This is child process (PID: %d)", getpid());
        msgsnd(mqid2, &msg2, sizeof(msg2), 0);

        // Exit the child process
        exit(0);
    } 

    // Parent process
    else {
        // Declare variable
        struct message msg;

        // Set signal handler for SIGINT
        signal(SIGINT, handle_sigint);

        // Print parent process message
        printf("I am the parent process (PID: %d)\n", getpid());

        // Send message to child process
        msg.mtype = 1;
        snprintf(msg.mtext, MSG_SIZE, "Hello Child! This is parent process (PID: %d)", getpid());
        msgsnd(mqid1, &msg, sizeof(msg), 0);

        // Receive response from child process
        msgrcv(mqid2, &msg, sizeof(msg), 2, 0);

        // Print received message
        printf("Parent process received message: %s\n", msg.mtext);

        // Wait for child process to exit
        wait(NULL);
    }

    // Exit the program
    return 0;
}