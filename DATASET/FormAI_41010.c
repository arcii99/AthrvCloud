//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/wait.h>

#define MSG_SIZE 1024

struct msgbuf{
    long msgtype;
    char msgtext[MSG_SIZE];
};

int main(){
    int msgqid;
    pid_t pid;

    key_t key=ftok("ipcdemo", 'a'); // generate a unique key for message queue

    msgqid=msgget(key, IPC_CREAT|0644); // create message queue with read and write permissions

    if(msgqid==-1){
        perror("Error in creating message queue");
        exit(EXIT_FAILURE);
    }

    pid=fork(); // create new process

    if(pid==0){ // child process
        struct msgbuf msg_rcv;
        msgrcv(msgqid, &msg_rcv, MSG_SIZE, getpid(), 0); // receive message from parent process
        printf("Child Process with PID %d received the message: %s\n", getpid(), msg_rcv.msgtext);
        exit(EXIT_SUCCESS); // terminate child process
    }
    else if(pid>0){ // parent process
        int status;
        struct msgbuf msg_snd;
        
        printf("Enter a message to send to child process: ");
        fgets(msg_snd.msgtext, MSG_SIZE, stdin); // read message from user
        
        msg_snd.msgtype=pid;
        msgsnd(msgqid, &msg_snd, strlen(msg_snd.msgtext)+1, 0); // send message to child process
        
        waitpid(pid, &status, 0); // wait for child process to finish
        printf("Parent Process with PID %d has sent the message: %s to Child Process with PID %d\n", getpid(), msg_snd.msgtext, pid);
        exit(EXIT_SUCCESS); // terminate parent process
    }
    else{ // error in forking
        perror("Error in forking");
        exit(EXIT_FAILURE);
    }

    return 0;
}