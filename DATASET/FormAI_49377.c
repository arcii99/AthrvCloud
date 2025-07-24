//FormAI DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/ipc.h> 
#include<sys/msg.h> 

#define MSGSIZE 100 

// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[MSGSIZE]; 
} message; 

int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.mesg_type = 1; 
  
    printf("Enter message : "); 
    fgets(message.mesg_text, MSGSIZE, stdin); 
  
    // msgsnd to send message 
    msgsnd(msgid, &message, sizeof(message), 0); 
  
    // display the message 
    printf("Data send is : %s \n", message.mesg_text); 
  
    return 0; 
}