//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100

// Structure for message queue
struct message {
    long msg_type;
    char msg_text[MAX_SIZE];
};

int main() {
    // Generate key for message queue
    key_t key = ftok("message_queue_program", 'Q');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Message queue created with key %d\n", key);

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("I am the child process with PID %d\n", getpid());

        // Receive message from parent
        struct message msg;
        if (msgrcv(msgid, &msg, MAX_SIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Child process received message: %s\n", msg.msg_text);

        // Modify message and send back to parent
        strcat(msg.msg_text, " - modified by child");
        msg.msg_type = 2;

        if (msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        printf("Child process sent modified message: %s\n", msg.msg_text);

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("I am the parent process with PID %d\n", getpid());

        // Send message to child
        struct message msg;
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello from parent process");

        if (msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        printf("Parent process sent message: %s\n", msg.msg_text);

        // Receive message from child
        if (msgrcv(msgid, &msg, MAX_SIZE, 2, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Parent process received modified message: %s\n", msg.msg_text);
    }

    // Destroy message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}