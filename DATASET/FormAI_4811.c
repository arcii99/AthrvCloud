//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MSG_SIZE 100

//structure for message queue
struct msgbuf{
    long mtype;
    char mtext[MSG_SIZE];
};

int main(){
    key_t key;
    int msgid;
    
    //generate unique key for message queue
    key = ftok("msg_sender_receiver", 65);
    
    //create message queue and get id
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    struct msgbuf message;
    
    pid_t child_pid = fork();    //fork a child process
    
    if(child_pid == -1){    //forking failed
        printf("Forking failed!\n");
        exit(1);
    }
    else if(child_pid == 0){    //this is the child process
        printf("Child process created with pid %d\n", getpid());
        printf("Waiting to receive message...\n");
        
        //receive message from parent
        msgrcv(msgid, &message, MSG_SIZE, 1, 0);
        
        printf("Message received in child process: %s\n", message.mtext);
        
        //modify message text and send back to parent
        strcat(message.mtext, " modified by child");
        message.mtype = 2;
        msgsnd(msgid, &message, sizeof(message), 0);
        
        printf("Message sent back to parent in child process: %s\n", message.mtext);
    }
    else{    //this is the parent process
        printf("Parent process created with pid %d\n", getpid());
        
        //initialize message struct and send to child
        strcpy(message.mtext, "Hello from parent");
        message.mtype = 1;
        msgsnd(msgid, &message, sizeof(message), 0);
        
        printf("Message sent to child in parent process: %s\n", message.mtext);
        printf("Waiting to receive modified message...\n");
        
        //receive modified message from child
        msgrcv(msgid, &message, MSG_SIZE, 2, 0);
        
        printf("Modified message received in parent process: %s\n", message.mtext);
    }
    
    //remove message queue
    msgctl(msgid, IPC_RMID, NULL);
    
    return 0;
}