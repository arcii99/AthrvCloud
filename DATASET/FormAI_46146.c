//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <signal.h>

// Data structure for message queue
struct message {
    long mtype;
    char mtext[50];
};

// Signal handler for SIGINT
void signalHandler(int signum) {
    printf("\nExiting...\n");
    exit(0);
}

int main() {
    signal(SIGINT, signalHandler); // Register signal handler for SIGINT

    int msgid; // Message queue ID
    key_t key; // Key for message queue

    if((key = ftok("progfile", 65)) == -1) { // Generate unique key
        perror("ftok error");
        exit(1);
    }

    // Create message queue and get its ID
    if((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        perror("msgget error");
        exit(1);
    }

    int pid = fork(); // Create child process

    // Child process
    if(pid == 0) {
        while(1) {
            struct message msg;

            // Receive message from parent
            if(msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0) == -1) {
                perror("msgrcv error");
                exit(1);
            }

            printf("Received message in child process: %s\n", msg.mtext);

            // Send acknowledgement message to parent
            msg.mtype = 2;
            strcpy(msg.mtext, "ACK");
            if(msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
                perror("msgsnd error");
                exit(1);
            }

            printf("Acknowledgement sent from child process\n");
        }
    }

    // Parent process
    else {
        while(1) {
            struct message msg;

            printf("Enter message to be sent to child process (max 50 characters): ");
            fgets(msg.mtext, 50, stdin);
            msg.mtype = 1;

            // Send message to child
            if(msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
              perror("msgsnd error");
              exit(1);
            }

            printf("Message sent from parent process\n");

            // Wait for acknowledgement from child
            if(msgrcv(msgid, &msg, sizeof(msg.mtext), 2, 0) == -1) {
              perror("msgrcv error");
              exit(1);
            }

            printf("Acknowledgement received in parent process: %s\n", msg.mtext);
        }
    }

    return 0;
}