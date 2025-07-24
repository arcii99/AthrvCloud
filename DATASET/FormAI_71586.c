//FormAI DATASET v1.0 Category: Interprocess communication ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
    long type;
    char message[256];
} message;

int main() {
    pid_t pid;
    int msqid;
    key_t key;
    message msg;

    if ((key = ftok("file.txt", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process is running.\n");

        // Receive message from parent
        if (msgrcv(msqid, &msg, sizeof(message) - sizeof(long), 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Child received message: %s\n", msg.message);

        // Send message to parent
        msg.type = 2;
        strcpy(msg.message, "Hello parent, this is child.");
        if (msgsnd(msqid, &msg, sizeof(message) - sizeof(long), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Child sent message to parent.\n");
    }
    else {
        // Parent process
        printf("Parent process is running.\n");

        // Send message to child
        msg.type = 1;
        strcpy(msg.message, "Hello child, this is parent.");
        if (msgsnd(msqid, &msg, sizeof(message) - sizeof(long), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Parent sent message to child.\n");

        // Receive message from child
        if (msgrcv(msqid, &msg, sizeof(message) - sizeof(long), 2, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Parent received message: %s\n", msg.message);

        // Wait for child to finish
        if (waitpid(pid, NULL, 0) == -1) {
            perror("waitpid");
            exit(1);
        }

        // Remove message queue
        if (msgctl(msqid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(1);
        }
    }

    return 0;
}