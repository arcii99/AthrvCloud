//FormAI DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 128

// Define the structure of the message
struct message {
    long mtype;
    char mtext[MSG_SIZE];
};

int main()
{
    // Generate a unique key for the message queue
    key_t key = ftok("progfile", 65);

    // Create the message queue with the generated key
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Check if the message queue was created successfully
    if (msgid == -1) {
        printf("Error creating message queue.\n");
        exit(1);
    }

    // Create a message structure to store the data
    struct message msg;

    // Define the recipient for the message
    msg.mtype = 1;

    // Ask the user for input
    printf("Enter a message to send: ");
    fgets(msg.mtext, MSG_SIZE, stdin);

    // Send the message to the recipient
    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Print a confirmation message
    printf("Message sent successfully.\n");

    // Receive a message from the sender
    if (msgrcv(msgid, &msg, sizeof(msg), 1, 0) == -1) {
        printf("Error receiving message.\n");
        exit(1);
    }

    // Print the received message
    printf("Received message: %s\n", msg.mtext);

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}