//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 1024

struct message {
    long msg_type;
    char msg_text[MAX_SIZE];
};

int main() {
    int msg_id;
    struct message msg;
    char buffer[MAX_SIZE];

    // create message queue
    msg_id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if(msg_id == -1) {
        perror("Error in creating message queue.");
        exit(EXIT_FAILURE);
    }

    // get message
    printf("Enter a message: ");
    fgets(buffer, MAX_SIZE, stdin);
    msg.msg_type = 1;
    strncpy(msg.msg_text, buffer, MAX_SIZE);
    msg.msg_text[MAX_SIZE - 1] = '\0';

    // send message
    if(msgsnd(msg_id, (void *)&msg, MAX_SIZE, 0) == -1) {
        perror("Error in sending message");
        exit(EXIT_FAILURE);
    }

    printf("Message sent.\n");

    // receive message
    if(msgrcv(msg_id, (void *)&msg, MAX_SIZE, 0, 0) == -1) {
        perror("Error in receiving message");
        exit(EXIT_FAILURE);
    }

    printf("Message received: %s\n", msg.msg_text);

    // remove message queue
    if(msgctl(msg_id, IPC_RMID, NULL) == -1) {
        perror("Error in removing message queue");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}