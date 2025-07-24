//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

//Structure for message queue
struct msg_struct {
    long mtype;
    char mtext[MSG_SIZE];
};

int main() {
    int pid;
    int msgqid;

    //Generating a unique key for the message queue
    key_t key = ftok("progfile", 65);

    //Creating a message queue
    msgqid = msgget(key, 0666 | IPC_CREAT);
    if (msgqid == -1) {
        printf("Error in creating message queue!\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Message queue created successfully with id: %d\n", msgqid);
    }

    //Forking a child process to act as receiver
    pid = fork();
    if (pid == -1) {
        printf("Error in forking a child process!\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        //Child process acting as receiver
        struct msg_struct msg_rcv;

        //Receiving messages from the message queue
        if (msgrcv(msgqid, &msg_rcv, MSG_SIZE, 1, 0) == -1) {
            printf("Error in receiving message!\n");
            exit(EXIT_FAILURE);
        }
        printf("Received message in child process: %s\n", msg_rcv.mtext);
        
    } else {
        //Parent process acting as sender
        struct msg_struct msg_send;
        printf("Enter message to be sent: ");
        scanf("%[^\n]%*c", msg_send.mtext);
        msg_send.mtype = 1;

        //Sending message to the message queue
        if (msgsnd(msgqid, &msg_send, MSG_SIZE, 0) == -1) {
            printf("Error in sending message!\n");
            exit(EXIT_FAILURE);
        } else {
            printf("Message sent successfully!\n");
        }
    }

    //Deleting the message queue
    if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
        printf("Error in deleting the message queue!\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Message queue deleted successfully!\n");
    }
    
    return 0;
}