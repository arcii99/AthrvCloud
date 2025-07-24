//FormAI DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 1024

typedef struct msgbuf {
    long m_type;
    char m_text[MAX_SIZE];
} MsgBuf;

int main() {
    key_t key;
    int msgid;
    MsgBuf message;

    // Generate a unique key
    if ((key = ftok("progfile", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the message queue
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    printf("The Message Queue ID is: %d\n", msgid);

    // Sending a message to the message queue
    message.m_type = 1;
    printf("Enter a message: ");
    fgets(message.m_text, MAX_SIZE, stdin);

    if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent: %s\n", message.m_text);

    // Receiving a message from the message queue
    if (msgrcv(msgid, &message, sizeof(message), 0, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Message received: %s", message.m_text);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}