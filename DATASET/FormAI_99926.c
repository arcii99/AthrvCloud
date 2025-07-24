//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h> 

#define MAX_TEXT 512 

struct message_buffer { 
    long message_type; 
    char message_text[MAX_TEXT]; 
}; 

int main() 
{ 
    key_t key; 
    int message_id; 
    struct message_buffer message; 

    // generate a unique key for message queue 
    key = ftok("progfile", 65); 

    // create a message queue and return its identifier 
    message_id = msgget(key, 0666 | IPC_CREAT); 

    printf("Enter some text: "); 
    fgets(message.message_text, MAX_TEXT, stdin); 

    // specify the message type 
    message.message_type = 1; 

    // send the message to the queue 
    msgsnd(message_id, &message, sizeof(message), 0); 

    // receive the message from the queue 
    msgrcv(message_id, &message, sizeof(message), 1, 0); 

    // display the message 
    printf("Received message from process 2: %s\n", message.message_text); 

    // delete the message queue 
    msgctl(message_id, IPC_RMID, NULL); 

    return 0; 
}