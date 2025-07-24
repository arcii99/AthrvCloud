//FormAI DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 200

struct message {
    long mtype;
    char mtext[MSG_SIZE];
};

int main() {
    int msgid;
    struct message msgbuf;
    key_t key;

    // Generate key
    key = ftok("msgqueue", 'M');
    if(key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if(msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Send message
    while(1) {
        printf("Enter message to send: ");
        fgets(msgbuf.mtext, MSG_SIZE, stdin);
        msgbuf.mtype = 1;
        if(msgsnd(msgid, &msgbuf, strlen(msgbuf.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        printf("Message sent.\n");
    }

    // Receive message
    while(1) {
        if(msgrcv(msgid, &msgbuf, MSG_SIZE, 0, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        printf("Received message: %s", msgbuf.mtext);
    }

    return 0;
}