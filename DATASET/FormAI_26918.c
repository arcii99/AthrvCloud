//FormAI DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define MSG_TYPE 1

// Structure for message queue
typedef struct {
    long mtype;
    char message[100];
} Msg;

void sender(int msgid) {
    printf("Enter message to send: ");
    char buff[100];
    fflush(stdin);
    fgets(buff, 100, stdin);
    Msg message;
    message.mtype = MSG_TYPE;
    strcpy(message.message, buff);
    msgsnd(msgid, &message, sizeof(message.message), 0);
}

void receiver(int msgid) {
    Msg message;
    msgrcv(msgid, &message, sizeof(message.message), MSG_TYPE, 0);
    printf("Message received: %s\n", message.message);
}

int main() {
    key_t key = ftok(".", 'A');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid < 0) {
        printf("Failed to create message queue\n");
        exit(1);
    }
    printf("Message queue created with ID = %d\n", msgid);
    pid_t pid = fork();
    if (pid < 0) {
        printf("Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        printf("Child process (Receiver)\n");
        while(1) {
            receiver(msgid);
        }
    } else {
        printf("Parent process (Sender)\n");
        while(1) {
            sender(msgid);
        }
    }
    return 0;
}