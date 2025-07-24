//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 256

/* Define the message structure */
struct message {
    long message_type;
    char message_text[MSG_SIZE];
};

/* Define a function for the child process */
void child_function(int queue_id) {
    /* Create a message */
    struct message msg;
    msg.message_type = 1; // Arbitrary message type

    /* Fill in the message text */
    snprintf(msg.message_text, MSG_SIZE, "Hello, parent process! This is the child speaking.");

    /* Send the message to the parent process */
    if (msgsnd(queue_id, &msg, sizeof(struct message), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    /* Exit the child process */
    exit(EXIT_SUCCESS);
}

int main() {
    /* Create a message queue */
    key_t key = ftok(".", 'q');
    int queue_id = msgget(key, 0666 | IPC_CREAT);
    if (queue_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    /* Create a child process */
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* This is the child process */
        child_function(queue_id);
    } else {
        /* This is the parent process */
        struct message msg;

        /* Receive the message from the child process */
        if (msgrcv(queue_id, &msg, sizeof(struct message), 0, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        /* Print the message to the console */
        printf("%s\n", msg.message_text);

        /* Remove the message queue */
        if (msgctl(queue_id, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }

    /* Exit the program */
    exit(EXIT_SUCCESS);
}