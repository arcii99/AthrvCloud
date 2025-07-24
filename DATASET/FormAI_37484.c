//FormAI DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define MSGKEY 75

typedef struct message {
    long messageType;
    char messageData[256];
} Message;

int main() {
    printf("Starting Interprocess Communication program...\n");

    // generate unique message queue key
    key_t messageQueueKey = ftok(".", 'm');

    // create message queue using the unique key
    int messageQueueId = msgget(messageQueueKey, IPC_CREAT | 0666);

    printf("Message queue created with ID %d\n", messageQueueId);

    pid_t childProcessId = fork();

    if (childProcessId == -1) {
        printf("Failed to fork process.\n");
        exit(1);
    }
    else if (childProcessId == 0) {
        // child process
        printf("Child process started.\n");

        // receive message from parent
        Message message;
        message.messageType = 1; // set message type to 1
        int receiveStatus = msgrcv(messageQueueId, &message, sizeof(message), 1, 0);

        if (receiveStatus == -1) {
            printf("Failed to receive message.\n");
            exit(1);
        }

        printf("Child received message: %s\n", message.messageData);

        // send message to parent
        message.messageType = 2; // set message type to 2
        sprintf(message.messageData, "Message received by child."); // set message data
        int sendStatus = msgsnd(messageQueueId, &message, sizeof(message), 0);

        if (sendStatus == -1) {
            printf("Failed to send message.\n");
            exit(1);
        }

        printf("Child sent message to parent.\n");

        exit(0); // terminate child process
    }
    else {
        // parent process
        printf("Parent process started.\n");

        // send message to child
        Message message;
        message.messageType = 1; // set message type to 1
        sprintf(message.messageData, "Hello from parent process!"); // set message data
        int sendStatus = msgsnd(messageQueueId, &message, sizeof(message), 0);

        if (sendStatus == -1) {
            printf("Failed to send message.\n");
            exit(1);
        }

        printf("Parent sent message to child.\n");

        // receive message from child
        message.messageType = 2; // set message type to 2
        int receiveStatus = msgrcv(messageQueueId, &message, sizeof(message), 2, 0);

        if (receiveStatus == -1) {
            printf("Failed to receive message.\n");
            exit(1);
        }

        printf("Parent received message: %s\n", message.messageData);
    }

    // remove message queue
    int removeStatus = msgctl(messageQueueId, IPC_RMID, NULL);

    if (removeStatus == -1) {
        printf("Failed to remove message queue.\n");
        exit(1);
    }

    printf("Interprocess Communication program completed.\n");

    return 0;
}