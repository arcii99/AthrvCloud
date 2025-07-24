//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT 512

typedef struct message {
    long int msg_type;
    char msg_text[MAX_TEXT];
} Message;

int main() {
    int pid = fork();
    int msgid;
    Message message;

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {
        // This is the child process that will receive messages
        msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
        if (msgid == -1) {
            perror("msgget");
            exit(EXIT_FAILURE);
        }

        while(1) {
            if (msgrcv(msgid, (void *)&message, MAX_TEXT, 0, 0) == -1) {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }
            printf("Received message: %s\n", message.msg_text);
            if (strcmp(message.msg_text, "exit") == 0) {
                exit(EXIT_SUCCESS);
            }
        }
    }
    else {
        // This is the parent process that will send messages
        msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
        if (msgid == -1) {
            perror("msgget");
            exit(EXIT_FAILURE);
        }

        while(1) {
            printf("Enter message to send to child process: ");
            fflush(stdout);
            fgets(message.msg_text, MAX_TEXT, stdin);

            // Remove trailing newline
            message.msg_text[strcspn(message.msg_text, "\n")] = 0;

            message.msg_type = 1;

            if (msgsnd(msgid, (void *)&message, MAX_TEXT, 0) == -1) {
                perror("msgsnd");
                exit(EXIT_FAILURE);
            }
            if (strcmp(message.msg_text, "exit") == 0) {
                exit(EXIT_SUCCESS);
            }
        }
    }

    return 0;
}