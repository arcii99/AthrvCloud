//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;
    int pid = getpid();
    struct msgbuf send_buf, recv_buf;

    key = ftok(".", 'a');
    if (key == -1) {
        perror("Failed to create key!");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Failed to create message queue!");
        exit(EXIT_FAILURE);
    }

    // Send a message to process B
    send_buf.mtype = 1;
    sprintf(send_buf.mtext, "Hello from process A (pid %d) to process B!", pid);
    if (msgsnd(msgid, (void*)&send_buf, MAX_MSG_SIZE, 0) == -1) {
        perror("Failed to send message!");
        exit(EXIT_FAILURE);
    }

    // Wait for a response from process B
    if (msgrcv(msgid, (void*)&recv_buf, MAX_MSG_SIZE, 2, 0) == -1) {
        perror("Failed to receive message!");
        exit(EXIT_FAILURE);
    }

    // Print out the response from process B
    printf("Process A (pid %d) received message from process B: %s\n", pid, recv_buf.mtext);

    // Send another message to process B
    send_buf.mtype = 3;
    sprintf(send_buf.mtext, "Goodbye from process A (pid %d) to process B!", pid);
    if (msgsnd(msgid, (void*)&send_buf, MAX_MSG_SIZE, 0) == -1) {
        perror("Failed to send message!");
        exit(EXIT_FAILURE);
    }

    // Wait for a response from process B
    if (msgrcv(msgid, (void*)&recv_buf, MAX_MSG_SIZE, 4, 0) == -1) {
        perror("Failed to receive message!");
        exit(EXIT_FAILURE);
    }

    // Print out the response from process B
    printf("Process A (pid %d) received message from process B: %s\n", pid, recv_buf.mtext);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("Failed to remove message queue!");
        exit(EXIT_FAILURE);
    }

    return 0;
}