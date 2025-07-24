//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 64

typedef struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE];
} MsgBuffer;

int main() {
    int qid;
    key_t key = ftok(".", 'm');
    if(key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if((qid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Enter message to send: ");
    char msg[MSG_SIZE];
    fgets(msg, MSG_SIZE, stdin);

    MsgBuffer msgbuf;
    msgbuf.mtype = 1;
    strncpy(msgbuf.mtext, msg, MSG_SIZE);

    if(msgsnd(qid, &msgbuf, sizeof(MsgBuffer), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Message sent successfully!\n");

    return 0;
}