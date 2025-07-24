//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>

#define MAXSIZE 1024 

struct message_buffer { 
    long message_type; 
    char message_text[MAXSIZE]; 
}message; 

int main() 
{ 
    key_t key; 
    int message_id; 

    // generate unique key 
    if((key = ftok("progfile", 65)) == -1){
        perror("ftok");
        exit(1);
    }

    // create message queue and get identifier
    if((message_id = msgget(key, 0666 | IPC_CREAT)) == -1){
        perror("msgget");
        exit(1);
    } 

    // sending message
    message.message_type = 1; 
    printf("Enter message : "); 
    fgets(message.message_text, MAXSIZE, stdin); 

    // send message to queue
    if(msgsnd(message_id, &message, sizeof(message.message_text), 0) == -1){
        perror("msgsnd");
        exit(1);
    }
    printf("Message sent successfully!\n"); 

    // receiving message
    if(msgrcv(message_id, &message, MAXSIZE, 1, 0) == -1){
        perror("msgrcv");
        exit(1);
    } 

    // print the message 
    printf("Received message : %s\n", message.message_text); 

    // delete message queue
    if(msgctl(message_id, IPC_RMID, NULL) == -1){
        perror("msgctl");
        exit(1);
    } 

    return 0; 
}