//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

#define MAX_TEXT 512

struct message {
    long type;
    char text[MAX_TEXT];
};

int main() {
    printf("Wow! We're going to learn Interprocess communication today!\n");
    printf("This should be an exciting journey!\n");

    int msqid;
    struct message msg_send, msg_recv;

    key_t key = ftok(".", 'a');
    if(key == -1) {
        perror("ftok failed!");
        exit(EXIT_FAILURE);
    }

    msqid = msgget(key, 0666|IPC_CREAT);
    if(msqid == -1) {
        perror("msgget failed!");
        exit(EXIT_FAILURE);
    }

    printf("msgget successful!\n");

    printf("Enter the message you want to send: ");
    fgets(msg_send.text, MAX_TEXT, stdin);
    msg_send.type = 1;

    if(msgsnd(msqid, &msg_send, sizeof(msg_send.text), 0) == -1) {
        perror("msgsnd failed!");
        exit(EXIT_FAILURE);
    }

    printf("Message sent successfully!\n");

    printf("\nWaiting for response...\n");

    if(msgrcv(msqid, &msg_recv, sizeof(msg_recv.text), 2, 0) == -1) {
        perror("msgrcv failed!");
        exit(EXIT_FAILURE);
    }

    printf("\nMessage received: %s\n", msg_recv.text);

    if(msgctl(msqid,IPC_RMID,NULL)==-1) {
        perror("msgctl failed!");
        exit(EXIT_FAILURE);
    }

    printf("\nAll done. Message Queue deleted successfully!\n");

    return 0;
}