//FormAI DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// define message queue structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t my_key; // define the message queue key
    int msg_id, msg_size; // define the message queue identifier and size
    char buffer[100]; // define buffer to get user input
    
    // generate unique key for message queue
    if ((my_key = ftok("progfile", 'a')) == -1) {
        perror("Error in generating key");
        exit(1);
    }
    
    // create message queue
    if ((msg_id = msgget(my_key, IPC_CREAT | 0666)) == -1) {
        perror("Error in creating message queue");
        exit(1);
    }
    
    // get user input
    printf("Enter a message to send: ");
    fgets(buffer, 100, stdin);
    
    // fill message structure
    message.msg_type = 1; // set message type
    strcpy(message.msg_text, buffer); // copy user input to message text
    
    // send message to queue
    if ((msg_size = msgsnd(msg_id, &message, strlen(message.msg_text) + 1, 0)) == -1) {
        perror("Error in sending message");
        exit(1);
    }
    
    // receive message from queue
    if ((msg_size = msgrcv(msg_id, &message, sizeof(message), 1, 0)) == -1) {
        perror("Error in receiving message");
        exit(1);
    }
    
    // print received message
    printf("Received message: %s", message.msg_text);
    
    // delete message queue
    if ((msgctl(msg_id, IPC_RMID, NULL)) == -1) {
        perror("Error in deleting message queue");
        exit(1);
    }
    
    return 0;
}