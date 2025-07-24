//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
// Hey there, folks! Are you ready to witness the magic of Interprocess Communication in C? 
// Buckle up, because we're about to create a program that will revolutionize the way you think about communication between processes!
// Let's start by including the necessary libraries.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Next, we'll define our message structure.
typedef struct message {
    long mtype;
    char mtext[100];
} message;

// Now, let's declare some variables that we'll be using later on.
key_t key;
int msgid;
message msg;

int main() {
    printf("Welcome to the world of IPC!\n");

    // Let's create a message queue using ftok.
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Error handling time!
    if (msgid == -1) {
        printf("Error creating message queue. Exiting...");
        exit(EXIT_FAILURE);
    }

    // Now, let's send a message to the message queue.
    msg.mtype = 1;
    printf("Enter a message to send to process 2: ");
    fgets(msg.mtext, 100, stdin);

    // Let's send the message!
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Message sent successfully.\n");

    // Time to receive a message from the message queue.
    msgrcv(msgid, &msg, sizeof(msg), 2, 0);
    printf("Message received from process 2: %s", msg.mtext);

    // Time to clean up the message queue.
    msgctl(msgid, IPC_RMID, NULL);

    printf("All done! Time to celebrate this amazing feat of Interprocess Communication in C!\n");
    return 0; 
}