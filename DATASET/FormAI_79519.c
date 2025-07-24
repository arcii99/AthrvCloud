//FormAI DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

#define MSG_SIZE 64 //limiting message size to 64 bytes

//Define the message structure
struct msg_struct{
    long msg_type; //message type 
    char msg[MSG_SIZE]; // message data
};

int main(){

    //Creating message queue for processes to communicate
    int msgid_msgq;
    key_t key_msgq;

    //Generate the unique key for the message queue
    if((key_msgq = ftok(".", 'a')) == -1){
        perror("ftok");
        exit(-1);
    }

    //Create the message queue
    if((msgid_msgq = msgget(key_msgq, IPC_CREAT | 0660)) == -1){
        perror("msgget");
        exit(-1);
    }

    //Creating 2 processes to send and receive messages
    pid_t pid;
    pid = fork();

    if(pid == -1){
        perror("fork");
        exit(-1);
    }
    else if (pid == 0){ //child process to receive messages
        struct msg_struct message_recv;
        message_recv.msg_type = 1; //message type set to 1

        while(1){
            //Receive message from the message queue
            if(msgrcv(msgid_msgq, &message_recv, MSG_SIZE, 1, 0) == -1){
                perror("msgrcv");
                exit(-1);
            }

            //Print received message
            printf("Message Received: %s\n", message_recv.msg);

            //Terminate the child process if "exit" message received
            if(strcmp(message_recv.msg, "exit") == 0){
                exit(0);
            }
        }
    }
    else{ //parent process to send messages
        struct msg_struct message_send;
        message_send.msg_type = 1; //message type set to 1

        while(1){
            //Get input message from the user
            printf("Enter message: ");
            fgets(message_send.msg, MSG_SIZE, stdin);

            //Send message to the message queue
            if(msgsnd(msgid_msgq, &message_send, strlen(message_send.msg)+1, IPC_NOWAIT) == -1){
                perror("msgsnd");
                exit(-1);
            }

            //Terminate the parent process if "exit" message sent
            if(strcmp(message_send.msg, "exit\n") == 0){
                exit(0);
            }
        }
    }
    return 0;
}