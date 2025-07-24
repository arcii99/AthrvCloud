//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX 50

struct message{
    long int type;
    char data[MAX];
}msg;

int main(){
    int msgid;
    key_t key;
    pid_t pid;

    //generate key
    if((key=ftok("progfile",65))==-1){
        perror("ftok");
        exit(1);
    }
    
    //create message queue
    if((msgid=msgget(key,0666|IPC_CREAT))==-1){
        perror("msgget");
        exit(1);
    }

    //fork a child process
    pid=fork();

    if(pid==-1){
        perror("fork");
        exit(1);
    }

    if(pid==0){ //child process
        printf("Child process waiting for message...\n");
        msgrcv(msgid,&msg,MAX,1,0);
        printf("Data received: %s\n",msg.data);
    }
    else{ //parent process
        printf("Enter message to send: ");
        fgets(msg.data,MAX,stdin);
        msg.type=1;

        //send message to child
        if(msgsnd(msgid,&msg,strlen(msg.data)+1,0)==-1){
            perror("msgsnd");
            exit(1);
        }
        printf("Message sent!\n");
    }

    //delete message queue
    if(msgctl(msgid,IPC_RMID,NULL)==-1){
        perror("msgctl");
        exit(1);
    }

    return 0;
}