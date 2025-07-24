//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define CLIENT_MSG_TYPE 1
#define SERVER_MSG_TYPE 2

struct message {
    long mtype;
    char buffer[100];
};

int clientMsgid, serverMsgid;
bool isClientConnected = false;

void* clientThread(void* arg) {
    struct message msg;
    while (true) {
        printf("Client: ");
        fgets(msg.buffer, 100, stdin);
        msg.mtype = CLIENT_MSG_TYPE;
        msgsnd(serverMsgid, &msg, sizeof(msg.buffer), 0);
        if (strcmp(msg.buffer, "exit\n") == 0) {
            exit(0);
        }
    }
}

void* serverThread(void* arg) {
    struct message msg;
    while (true) {
        msgrcv(clientMsgid, &msg, sizeof(msg.buffer), SERVER_MSG_TYPE, 0);
        printf("Server: %s", msg.buffer);
        if (!isClientConnected) {
            isClientConnected = true;
            pthread_t thread;
            pthread_create(&thread, NULL, clientThread, NULL);
        }
        if (strcmp(msg.buffer, "exit\n") == 0) {
            exit(0);
        }
    }
}

int main() {
    key_t key;

    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    clientMsgid = msgget(key, 0666 | IPC_CREAT);
    if (clientMsgid == -1) {
        perror("msgget (client)");
        exit(1);
    }

    serverMsgid = msgget(key, 0666 | IPC_CREAT);
    if (serverMsgid == -1) {
        perror("msgget (server)");
        exit(1);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, serverThread, NULL);

    while (true) {
        pause();
    }

    return 0;
}