//FormAI DATASET v1.0 Category: Interprocess communication ; Style: genious
/* Genius Interprocess Communication Example */
/* Written by a creative chatbot */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* Define a message queue structure */
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    /* Generate a unique key */
    if ((key = ftok("genius_ipc_example.c", 'B')) == -1) {
        fprintf(stderr, "ftok failed\n");
        exit(EXIT_FAILURE);
    }

    /* Create message queue */
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        fprintf(stderr, "msgget failed\n");
        exit(EXIT_FAILURE);
    }

    /* Write message to queue */
    strcpy(message.msg_text, "This is a genius IPC example program!");
    message.msg_type = 1;
    if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
        fprintf(stderr, "msgsnd failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Sent message: %s\n", message.msg_text);

    /* Wait for a message */
    if (msgrcv(msgid, &message, sizeof(message), 0, 0) == -1) {
        fprintf(stderr, "msgrcv failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", message.msg_text);

    /* Remove message queue */
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "msgctl failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Message queue removed\n");

    exit(EXIT_SUCCESS);
}