//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MESSAGE_LENGTH 50

struct message {
    long message_type;
    char message_content[MAX_MESSAGE_LENGTH];
};

int main() {
    int message_queue_key = ftok(".", 'm');
    int message_queue_id = msgget(message_queue_key, 0666 | IPC_CREAT);
    if(message_queue_id == -1) {
        printf("Error creating message queue.\n");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();
    if(child_pid == -1) {
        printf("Error forking child process.\n");
        exit(EXIT_FAILURE);
    }
    else if(child_pid == 0) {
        struct message outgoing_message;
        outgoing_message.message_type = 1;
        printf("Enter a message for the parent process: ");
        fgets(outgoing_message.message_content, MAX_MESSAGE_LENGTH, stdin);
        msgsnd(message_queue_id, &outgoing_message, sizeof(outgoing_message), 0);
        exit(EXIT_SUCCESS);
    }
    else {
        struct message incoming_message;
        msgrcv(message_queue_id, &incoming_message, sizeof(incoming_message), 1, 0);
        printf("Parent process received message from child process: %s", incoming_message.message_content);
        msgctl(message_queue_id, IPC_RMID, NULL);
        exit(EXIT_SUCCESS);
    }
}