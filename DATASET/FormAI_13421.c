//FormAI DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

#define MAX_MSG_SIZE 512

typedef struct msgbuf_t {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} MessageBuffer;

int main() {
    int parent_process_id = getpid();
    int child_process_id = fork();
    key_t message_key = ftok(".", 'a');
    int message_queue_id = msgget(message_key, IPC_CREAT | 0666);
    MessageBuffer message_buffer;

    if (child_process_id == -1) {
        printf("Failed to fork child process!");
        exit(EXIT_FAILURE);
    } else if (child_process_id == 0) {
        // Child process
        printf("Child process sending message to parent process\n");

        // Preparing message buffer
        message_buffer.mtype = 1; // message type
        strcpy(message_buffer.mtext, "Hello from child process");

        // Sending message
        if (msgsnd(message_queue_id, &message_buffer, MAX_MSG_SIZE, 0) == -1) {
            printf("Failed to send message from child to parent process!");
        } else {
            printf("Message sent successfully from child to parent process!");
        }
    } else {
        // Parent process
        printf("Parent process receiving message from child process\n");

        // Receiving message
        if (msgrcv(message_queue_id, &message_buffer, MAX_MSG_SIZE, 1, 0) == -1) {
            printf("Failed to receive message from child process!");
        } else {
            printf("Message received successfully from child process: %s\n", message_buffer.mtext);
        }
    }

    return EXIT_SUCCESS;
}