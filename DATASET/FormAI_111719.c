//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

struct message {
    long type;
    char text[MSG_SIZE];
};

int main() {
    int key = ftok("process_communication", 'A');
    int msg_queue_id = msgget(key, 0600 | IPC_CREAT);
    pid_t pid;

    if (msg_queue_id == -1) {
        perror("Error creating message queue.");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("Error forking child process.");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // child process
        struct message msg;

        if (msgrcv(msg_queue_id, &msg, MSG_SIZE, 1, 0) == -1) {
            perror("Error receiving message in child process.");
            exit(EXIT_FAILURE);
        }

        printf("Child process received message: %s\n", msg.text);

        strncpy(msg.text, "Message received by child process.", MSG_SIZE);

        msg.type = 2;

        if (msgsnd(msg_queue_id, &msg, MSG_SIZE, 0) == -1) {
            perror("Error sending message from child process.");
            exit(EXIT_FAILURE);
        }

        _exit(EXIT_SUCCESS);

    } else {
        // parent process
        struct message msg;
      
        strncpy(msg.text, "Hello from parent process.", MSG_SIZE);

        msg.type = 1;

        if (msgsnd(msg_queue_id, &msg, MSG_SIZE, 0) == -1) {
            perror("Error sending message from parent process.");
            exit(EXIT_FAILURE);
        }

        if (msgrcv(msg_queue_id, &msg, MSG_SIZE, 2, 0) == -1) {
            perror("Error receiving message in parent process.");
            exit(EXIT_FAILURE);
        }

        printf("Parent process received message: %s\n", msg.text);

        if (msgctl(msg_queue_id, IPC_RMID, NULL) == -1) {
            perror("Error removing message queue.");
            exit(EXIT_FAILURE);
        }

        wait(NULL);

        exit(EXIT_SUCCESS);
    }
}