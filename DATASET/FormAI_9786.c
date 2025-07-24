//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 1024

typedef struct {
    long mtype;
    char mtext[MSG_SIZE];
} Message;

int main() {
    key_t key;
    int msgid;
    Message message;

    // Generate a unique key
    if ((key = ftok("progfile", 'a')) == -1) {
        perror("ftok error!");
        exit(EXIT_FAILURE);
    }

    // Create a message queue
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget error!");
        exit(EXIT_FAILURE);
    }

    /*
     * Sender process sends messages to the message queue
     */
    printf("========== Sender Process ==========\n");
    printf("Enter 'exit' to quit.\n");

    while (1) {
        // Read input from the user
        printf("Enter message to send: ");
        fgets(message.mtext, MSG_SIZE, stdin);

        // Remove trailing newline character
        message.mtext[strcspn(message.mtext, "\n")] = 0;

        // Check if user wants to quit
        if (strcmp(message.mtext, "exit") == 0) {
            break;
        }

        // Set the message type to 1
        message.mtype = 1;

        // Send the message to the message queue
        if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
            perror("msgsnd error!");
        }
    }

    /*
     * Receiver process receives messages from the message queue
     */
    printf("========== Receiver Process ==========\n");

    while (1) {
        // Receive a message from the message queue
        if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
            perror("msgrcv error!");
            exit(EXIT_FAILURE);
        }

        // Print the received message
        printf("Message received: %s\n", message.mtext);

        // Check if received message is "exit"
        if (strcmp(message.mtext, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl error!");
        exit(EXIT_FAILURE);
    }

    return 0;
}