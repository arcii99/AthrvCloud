//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define KEY 1234

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    // Create a message queue
    int msgid = msgget(KEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("Error in creating message queue");
        exit(EXIT_FAILURE);
    }

    int pid = fork();
    if (pid == -1) {
        perror("Error in forking");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process

        // Send message to parent process
        struct message msg;
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello from Child Process!");
        if (msgsnd(msgid, &msg, sizeof(struct message), 0) == -1) {
            perror("Error in sending message");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        // Parent process

        // Receive message from child process
        struct message msg;
        while (msgrcv(msgid, &msg, sizeof(struct message), 1, 0) == -1);

        printf("Message received from Child Process: %s\n", msg.msg_text);

        // Remove message queue
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("Error in removing message queue");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

    return 0;
}