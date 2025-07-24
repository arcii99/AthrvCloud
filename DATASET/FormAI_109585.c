//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

#define MSG_SIZE 100 
#define MSG_PERM 0666 
#define MAX_SIZE 10 

typedef struct msg_buffer { 
    long msg_type; 
    char msg_text[MSG_SIZE]; 
}msg;

int main() 
{ 
    int msg_id; 
    msg message; 

    struct msqid_ds buf; 

    // Generating a unique key 
    key_t key = ftok("prog", 65); 

    // Creating a message queue 
    msg_id = msgget(key, MSG_PERM | IPC_CREAT); 

    // Entering the message 
    printf("Enter the message: "); 

    fgets(message.msg_text, MSG_SIZE, stdin); 
    message.msg_type = 1; 

    // Sending the message 
    msgsnd(msg_id, &message, sizeof(message), 0); 

    printf("Message Sent - %s", message.msg_text); 

    // Checking the message queue status 
    while (1) { 
        msgctl(msg_id, IPC_STAT, &buf); 

        if (buf.msg_qnum >= MAX_SIZE) { 
            // Receiving the message 
            msgrcv(msg_id, &message, sizeof(msg), 1, IPC_NOWAIT); 

            printf("Message Received - %s", message.msg_text); 
            break; 
        } 
    } 

    // Deleting the message queue 
    msgctl(msg_id, IPC_RMID, NULL); 

    return 0; 
}