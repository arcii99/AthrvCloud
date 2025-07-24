//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <pthread.h>

#define SENDER1 1
#define SENDER2 2
#define RECEIVER 3

struct message {
    long mtype;
    char mtext[100];
};

int msgqid;

void *sender1(void *arg) {
    struct message msg;
    msg.mtype = SENDER1;
    sprintf(msg.mtext, "Hello from sender1");
    while (1) {
        if (msgsnd(msgqid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        sleep(1);
    }
}

void *sender2(void *arg) {
    struct message msg;
    msg.mtype = SENDER2;
    sprintf(msg.mtext, "Hello from sender2");
    while (1) {
        if (msgsnd(msgqid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        sleep(2);
    }
}

void *receiver(void *arg) {
    struct message msg;
    while (1) {
        if (msgrcv(msgqid, &msg, sizeof(msg.mtext), RECEIVER, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        printf("Received message: %s\n", msg.mtext);
    }
}

int main() {
    pthread_t send1, send2, recv;
    key_t key;

    // Create unique key for message queue
    if ((key = ftok(".", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create message queue
    if ((msgqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    // Create sender1 thread
    if (pthread_create(&send1, NULL, sender1, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Create sender2 thread
    if (pthread_create(&send2, NULL, sender2, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Create receiver thread
    if (pthread_create(&recv, NULL, receiver, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Join threads
    pthread_join(send1, NULL);
    pthread_join(send2, NULL);
    pthread_join(recv, NULL);

    // Delete message queue
    if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}