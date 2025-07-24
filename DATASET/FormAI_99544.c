//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 100

struct message {
    long mtype;
    char data[MSG_SIZE];
};

int main() {
    int id1, id2;
    key_t key1, key2;
    struct message msgbuf;

    // create unique key for message queues
    key1 = ftok(".", 'a');
    key2 = ftok(".", 'b');

    // create message queue 1
    if ((id1 = msgget(key1, IPC_CREAT | 0666)) < 0) {
        perror("msgget");
        exit(1);
    }

    // create message queue 2
    if ((id2 = msgget(key2, IPC_CREAT | 0666)) < 0) {
        perror("msgget");
        exit(1);
    }

    // send message from process 1 to process 2
    strcpy(msgbuf.data, "Hello from process 1");
    msgbuf.mtype = 1;
    if (msgsnd(id2, &msgbuf, strlen(msgbuf.data) + 1, 0) < 0) {
        perror("msgsnd");
        exit(1);
    }

    // receive message from process 2 in process 1
    if (msgrcv(id1, &msgbuf, MSG_SIZE, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }
    printf("Process 1 received message from process 2: %s\n", msgbuf.data);

    // send message from process 2 to process 1
    strcpy(msgbuf.data, "Hello from process 2");
    msgbuf.mtype = 2;
    if (msgsnd(id1, &msgbuf, strlen(msgbuf.data) + 1, 0) < 0) {
        perror("msgsnd");
        exit(1);
    }

    // receive message from process 1 in process 2
    if (msgrcv(id2, &msgbuf, MSG_SIZE, 2, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }
    printf("Process 2 received message from process 1: %s\n", msgbuf.data);

    // destroy message queue 1
    if (msgctl(id1, IPC_RMID, NULL) < 0) {
        perror("msgctl");
        exit(1);
    }

    // destroy message queue 2
    if (msgctl(id2, IPC_RMID, NULL) < 0) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}