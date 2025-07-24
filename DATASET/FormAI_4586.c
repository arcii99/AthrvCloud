//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
/* This program demonstrates an interprocess communication example using message queues */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 256

/* A message structure */
typedef struct message {
    long type;              /* message type */
    char text[MAX_MSG_SIZE];/* message body */
} message_t;

/* Function for sending messages */
void sendMessage(int qid, const void *msgPtr, size_t msgSize, long msgType) 
{
    message_t sndMsg;
    sndMsg.type = msgType;
    memcpy(sndMsg.text, msgPtr, msgSize);
    if (msgsnd(qid, &sndMsg, sizeof(sndMsg.text), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }
    printf("Sent message: \"%s\"\n", (char*)msgPtr);
}

/* Function for receiving messages */
void receiveMessage(int qid, void *msgPtr, size_t msgSize, long msgType)
{
    message_t rcvMsg;
    if (msgrcv(qid, &rcvMsg, sizeof(rcvMsg.text), msgType, 0) == -1) {
        perror("msgrcv failed");
        exit(1);
    }
    memcpy(msgPtr, rcvMsg.text, msgSize);
    printf("Received message: \"%s\"\n", (char*)msgPtr);
}

int main()
{
    int qid;                    /* message queue id */
    key_t key;                  /* message queue key */
    char msg[MAX_MSG_SIZE];     /* message buffer */

    /* Generate a unique message queue key */
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok failed");
        exit(1);
    }

    /* Create the message queue */
    if ((qid = msgget(key, IPC_CREAT|0666)) == -1) {
        perror("msgget failed");
        exit(1);
    }

    /* Send a message */
    strcpy(msg, "Hello, world!");
    sendMessage(qid, msg, strlen(msg)+1, 1);

    /* Receive a message */
    receiveMessage(qid, msg, MAX_MSG_SIZE, 1);

    return 0;
}