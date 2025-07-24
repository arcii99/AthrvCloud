//FormAI DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT 512
#define MSG_TYPE_1 1
#define MSG_TYPE_2 2

struct msgbuf {
    long mtype;
    char mtext[MAX_TEXT];
};

int main() {
    pid_t pid;
    int qid1, qid2;
    key_t key1 = ftok(".", 'a');//to generate System V IPC key for message queue 1
    key_t key2 = ftok(".", 'b');//to generate System V IPC key for message queue 2
    struct msgbuf msg1, msg2;

    if ((qid1 = msgget(key1, IPC_CREAT | 0666)) == -1) {//creating message queue 1
        perror("msgget");  
        exit(1);  
    }

    if ((qid2 = msgget(key2, IPC_CREAT | 0666)) == -1) {//creating message queue 2
        perror("msgget");  
        exit(1);  
    }

    pid = fork();

    if(pid < 0) {
        perror("fork");
        exit(1);
    }
    else if(pid > 0) {//parent process sending message
        printf("Parent process sending message...\n");
        msg1.mtype = MSG_TYPE_1;
        strcpy(msg1.mtext, "Hello from parent");
        if (msgsnd(qid1, &msg1, MAX_TEXT, 0) == -1) {//sending message to queue 1
            perror("msgsnd");  
            exit(1);  
        }

        printf("Parent process waiting for response...\n");
        if (msgrcv(qid2, &msg2, MAX_TEXT, MSG_TYPE_2, 0) == -1) {//receiving message from queue 2
            perror("msgrcv");  
            exit(1);  
        }
        printf("Parent process received response: %s\n", msg2.mtext);
    }
    else {//child process receiving message
        printf("Child process waiting for message...\n");
        if (msgrcv(qid1, &msg1, MAX_TEXT, MSG_TYPE_1, 0) == -1) {//receiving message from queue 1
            perror("msgrcv");  
            exit(1);  
        }
        printf("Child process received message: %s\n", msg1.mtext);

        printf("Child process sending response...\n");
        msg2.mtype = MSG_TYPE_2;
        strcpy(msg2.mtext, "Hello from child");
        if (msgsnd(qid2, &msg2, MAX_TEXT, 0) == -1) {//sending message to queue 2
            perror("msgsnd");  
            exit(1);  
        }
    }

    return 0;
}