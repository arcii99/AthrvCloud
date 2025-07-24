//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
/*Hello Interprocess Communication!*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

/*Define the message structure*/
struct message{
    long msgtype;
    char data[100];
};

int main(){
    int msgid;
    struct message msgbuf;
    key_t key;

    /*Generate a unique key*/
    key = ftok("IPCExample", 'a');

    /*Create the message queue*/
    msgid = msgget(key, 0666 | IPC_CREAT);

    /*Check if the queue was created successfully*/
    if (msgid == -1){
        printf("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    printf("Hello! I am the sender process!\n");

    /*Get the input from the user*/
    printf("Enter the message to be sent: ");
    fgets(msgbuf.data, 100, stdin);

    /*Set the message type*/
    msgbuf.msgtype = 1;

    /*Send the message*/
    msgsnd(msgid, &msgbuf, sizeof(msgbuf.data), 0);

    printf("Message sent successfully! Waiting for receiver...\n");

    /*Wait for the receiver to read the message*/
    msgrcv(msgid, &msgbuf, sizeof(msgbuf.data), 2, 0);

    printf("Message received by receiver: %s\n", msgbuf.data);

    /*Delete the message queue*/
    msgctl(msgid, IPC_RMID, NULL);

    printf("Message queue deleted.\n");

    return 0;
}