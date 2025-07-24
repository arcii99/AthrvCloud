//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
/* 

This is a unique example of interprocess communication in C, where both parent and child processes are sending 
and receiving messages to each other back and forth.

*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT_SIZE 100

struct msgbuf {
    long mtype;
    char mtext[MAX_TEXT_SIZE];
};

int main() {
    key_t key;
    int msgid;
    pid_t pid;
    struct msgbuf message;
    char buffer[MAX_TEXT_SIZE];

    // generate unique key
    if ((key = ftok("msgqueue", 'B')) == -1) {
        perror("ftok");
        return 1;
    }

    // create message queue
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        return 1;
    }

    // fork a child process
    if ((pid = fork()) == -1) {
        perror("fork");
        return 1;
    }

    // parent process continuously sends messages to child process
    if (pid > 0) {
        while (1) {
            printf("Enter a message to send to the child process: ");
            fgets(buffer, MAX_TEXT_SIZE, stdin);
            strcpy(message.mtext, buffer);
            message.mtype = 1;
            if (msgsnd(msgid, &message, strlen(message.mtext) + 1, 0) == -1) {
                perror("msgsnd");
                return 1;
            }
            printf("Message sent successfully!\n");
        }
    }

    // child process continuously receives messages from parent process
    if (pid == 0) {
        while (1) {
            if (msgrcv(msgid, &message, MAX_TEXT_SIZE, 1, 0) == -1) {
                perror("msgrcv");
                return 1;
            }
            printf("Child process received message: %s", message.mtext);
            printf("Enter a message to send to the parent process: ");
            fgets(buffer, MAX_TEXT_SIZE, stdin);
            strcpy(message.mtext, buffer);
            message.mtype = 2;
            if (msgsnd(msgid, &message, strlen(message.mtext) + 1, 0) == -1) {
                perror("msgsnd");
                return 1;
            }
            printf("Message sent successfully!\n");
        }
    }

    return 0;
}