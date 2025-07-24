//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdio.h> 
  
#define MAX 10 
  
struct msg_buffer { 
    long msg_type; 
    char msg_text[MAX]; 
} msg; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("prog.c", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    msg.msg_type = 1; 
  
    printf("Enter message to send: "); 
    fgets(msg.msg_text, MAX, stdin); 
  
    // msgsnd to send message 
    msgsnd(msgid, &msg, sizeof(msg), 0); 
  
    // display the message 
    printf("Data sent is : %s \n", msg.msg_text); 
  
    return 0; 
}