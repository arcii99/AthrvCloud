//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 128

// Declare the structure for the message
struct message {
    long msg_type; // Message type (must be >0)
    char msg_text[MSG_SIZE]; // Message body
};

// Define the key for the message queue
#define MSG_QUEUE_KEY 0xABCD1234

int main() {
    int msgid; // Message queue ID
    struct message msg; // Message buffer

    // Create the message queue
    if((msgid = msgget(MSG_QUEUE_KEY, IPC_CREAT|0666)) == -1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid_t pid = fork();

    // Check for errors with fork
    if(pid == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    // Child process
    if(pid == 0) {
        // Send a message to the parent
        struct message child_msg;
        child_msg.msg_type = 1;
        strcpy(child_msg.msg_text, "Hello from the child process!");
        if(msgsnd(msgid, &child_msg, MSG_SIZE, 0) == -1) {
            perror("Error sending message from child");
            exit(EXIT_FAILURE);
        }

        // Wait for a message from the parent
        struct message parent_msg;
        if(msgrcv(msgid, &parent_msg, MSG_SIZE, 2, 0) == -1) {
            perror("Error receiving message from parent");
            exit(EXIT_FAILURE);
        }
        printf("Child received message from parent: %s\n", parent_msg.msg_text);

        // Clean up the message queue
        if(msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("Error cleaning up message queue");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

    // Parent process
    else {
        // Wait for a message from the child
        struct message child_msg;
        if(msgrcv(msgid, &child_msg, MSG_SIZE, 1, 0) == -1) {
            perror("Error receiving message from child");
            exit(EXIT_FAILURE);
        }
        printf("Parent received message from child: %s\n", child_msg.msg_text);

        // Send a message to the child
        struct message parent_msg;
        parent_msg.msg_type = 2;
        strcpy(parent_msg.msg_text, "Hello from the parent process!");
        if(msgsnd(msgid, &parent_msg, MSG_SIZE, 0) == -1) {
            perror("Error sending message from parent");
            exit(EXIT_FAILURE);
        }

        // Wait for the child process to finish
        int child_status;
        waitpid(pid, &child_status, 0);

        // Clean up the message queue
        if(msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("Error cleaning up message queue");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
}