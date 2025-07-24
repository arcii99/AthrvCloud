//FormAI DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 512
#define MSG_TYPE 1

// Define message structure
typedef struct msgbuf {
    long mtype; // Used for message type
    char mtext[MSG_SIZE]; // Actual message data
} message;

// Declare function to handle Ctrl-C interrupts
void sigint_handler(int sig) {
    printf("Shutting down...\n");
    exit(0);
}

int main() {
    pid_t pid;
    key_t key;
    int msgid;
    message msg;
    char buffer[MSG_SIZE];

    // Install signal handler for Ctrl-C
    signal(SIGINT, sigint_handler);

    // Generate unique key
    key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Check for errors creating message queue
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", msgid);

    // Fork new process
    pid = fork();

    if (pid == 0) {
        // Child process - receive messages from parent
        while (1) {
            // Receive message from parent
            msgrcv(msgid, &msg, sizeof(message), MSG_TYPE, 0);
            printf("Received message: %s", msg.mtext);
        }
    } else if (pid > 0) {
        // Parent process - send messages to child
        while (1) {
            // Get input message from user
            printf("Enter message: ");
            fgets(buffer, sizeof(buffer), stdin);

            // Create message object
            msg.mtype = MSG_TYPE;
            memcpy(msg.mtext, buffer, MSG_SIZE);

            // Send message to child
            msgsnd(msgid, &msg, sizeof(message), 0);
        }
    } else {
        // Error creating child process
        perror("fork");
        exit(1);
    }

    return 0;
}