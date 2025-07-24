//FormAI DATASET v1.0 Category: Interprocess communication ; Style: detailed
/* C Interprocess Communication Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* Define message buffer structure */
struct message_buffer {
    long message_type;
    char message_text[100];
} message;

int main() {
    /* Declare variables */
    int message_queue_id;
    key_t message_queue_key;
    pid_t child_process_id;

    /* Generate message queue key */
    message_queue_key = ftok(".", 'M');

    /* Create message queue */
    message_queue_id = msgget(message_queue_key, 0666 | IPC_CREAT);

    /* Check if message queue was successfully created */
    if (message_queue_id == -1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    /* Fork a child process */
    child_process_id = fork();

    /* Check if fork was successful */
    if (child_process_id == -1) {
        perror("Error forking child process");
        exit(EXIT_FAILURE);
    }

    /* Child process code */
    if (child_process_id == 0) {
        /* Declare variables */
        char message_text[100] = "Hello from child process!";

        /* Send message to message queue */
        message.message_type = 1;
        strncpy(message.message_text, message_text, 100);
        if (msgsnd(message_queue_id, &message, sizeof(message), 0) == -1) {
            perror("Error sending message from child process");
            exit(EXIT_FAILURE);
        }

        /* Exit child process */
        exit(EXIT_SUCCESS);
    }

    /* Parent process code */
    if (child_process_id > 0) {
        /* Receive message from message queue */
        if (msgrcv(message_queue_id, &message, sizeof(message), 1, 0) == -1) {
            perror("Error receiving message in parent process");
            exit(EXIT_FAILURE);
        }

        /* Print received message */
        printf("Received message from child process: %s\n", message.message_text);

        /* Remove message queue */
        if (msgctl(message_queue_id, IPC_RMID, NULL) == -1) {
            perror("Error removing message queue");
            exit(EXIT_FAILURE);
        }

        /* Exit parent process */
        exit(EXIT_SUCCESS);
    }

    /* If code reaches here, something went wrong */
    exit(EXIT_FAILURE);
}