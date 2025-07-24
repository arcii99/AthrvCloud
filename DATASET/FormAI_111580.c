//FormAI DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct data {
    long int msg_type;
    char msg_text[100];
};

int main(){
    pid_t pid;
    key_t key;
    int msgid;
    
    struct data message;
    
    key = ftok("progfile", 65);
    
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;
    
    printf("Enter message: ");
    fgets(message.msg_text, 100, stdin);
    
    pid = fork();
    
    if(pid == 0){
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Message received: %s", message.msg_text);
    }
    else{
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Message sent: %s", message.msg_text);
    }
    
    return 0;
}