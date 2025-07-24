//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX_TEXT 512

struct msgbuf {
    long mtype;
    char mtext[MAX_TEXT];
};

int main() {
    int key = ftok("ipccommunication", 'B');
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if(msgid == -1) {
        fprintf(stderr, "Error: Failed to create message queue!\n");
        exit(EXIT_FAILURE);
    }

    struct msgbuf msg;
    int running = 1;

    while(running) {
        printf("Enter text to send: ");
        fgets(msg.mtext, MAX_TEXT, stdin);
        msg.mtype = 1;

        if(msgsnd(msgid, &msg, MAX_TEXT, 0) == -1) {
            fprintf(stderr, "Error: Failed to send message!\n");
            exit(EXIT_FAILURE);
        }

        if(strncmp(msg.mtext, "exit", 4) == 0) {
            running = 0;
        }
    }

    if(msgctl(msgid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "Error: Failed to remove message queue!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}