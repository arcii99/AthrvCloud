//FormAI DATASET v1.0 Category: Interprocess communication ; Style: distributed
/* A distributed C Interprocess communication example program */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MSG_SIZE 64 /// max size of the message
#define KEY_1 1111  /// key for message queue 1
#define KEY_2 2222  /// key for message queue 2

typedef struct {
    long mtype;
    char mtext[MSG_SIZE];
} msgbuf;

int main() {
    pid_t pid;
    key_t key;
    int msgid1, msgid2;
    msgbuf msg;

    /* Create first message queue */
    if ((msgid1 = msgget(KEY_1, IPC_CREAT | 0666)) == -1) {
        perror("msgget for message queue 1 failed");
        exit(EXIT_FAILURE);
    }

    /* Create second message queue */
    if ((msgid2 = msgget(KEY_2, IPC_CREAT | 0666)) == -1) {
        perror("msgget for message queue 2 failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  /// Child process
        while(1) {
            /* Read message from message queue 1 */
            if (msgrcv(msgid1, &msg, MSG_SIZE, 1, 0) == -1) {
                perror("msgrcv for message queue 1 failed");
                exit(EXIT_FAILURE);
            }
            printf("Child: Received message: %s\n", msg.mtext);

            /* Send message to message queue 2 */
            strcpy(msg.mtext, "Hello Parent!");
            msg.mtype = 2;
            if (msgsnd(msgid2, &msg, strlen(msg.mtext) + 1, 0) == -1) {
                perror("msgsnd for message queue 2 failed");
                exit(EXIT_FAILURE);
            }
            printf("Child: Sent message to parent.\n");
        }
    } else {  /// Parent process
        while(1) {
            /* Send message to message queue 1 */
            strcpy(msg.mtext, "Hello Child!");
            msg.mtype = 1;
            if (msgsnd(msgid1, &msg, strlen(msg.mtext) + 1, 0) == -1) {
                perror("msgsnd for message queue 1 failed");
                exit(EXIT_FAILURE);
            }
            printf("Parent: Sent message to child.\n");

            /* Read message from message queue 2 */
            if (msgrcv(msgid2, &msg, MSG_SIZE, 2, 0) == -1) {
                perror("msgrcv for message queue 2 failed");
                exit(EXIT_FAILURE);
            }
            printf("Parent: Received message: %s\n", msg.mtext);
        }
        wait(NULL);
    }

    /* Delete message queues */
    msgctl(msgid1, IPC_RMID, NULL);
    msgctl(msgid2, IPC_RMID, NULL);

    return 0;
}