//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

#define MSG_SIZE 100

typedef struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE];
} message;

void* send_msg(void *args) {
    key_t key = ftok("msgqueue_program", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    message msg;
    msg.mtype = 1;
    while(1) {
        printf("\nEnter message to send to receiver: ");
        scanf("%s", msg.mtext);
        msgsnd(msgid, &msg, strlen(msg.mtext), 0);
        printf("Message sent!\n");
    }
}

void* recv_msg(void *args) {
    key_t key = ftok("msgqueue_program", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    message msg;
    msg.mtype = 1;
    while(1) {
        msgrcv(msgid, &msg, MSG_SIZE, 1, 0);
        printf("\nReceived message: %s\n", msg.mtext);
    }
}

int main() {
    pthread_t send_thread, recv_thread;
    pthread_create(&send_thread, NULL, send_msg, NULL);
    pthread_create(&recv_thread, NULL, recv_msg, NULL);
    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);
    return 0;
}