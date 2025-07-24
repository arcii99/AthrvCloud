//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

//define message structure
struct message_struct {
    long int message_type;
    char message_text[50];
};

int main() {
    //declare variables
    key_t key;
    int message_id;
    struct message_struct message;

    //generate unique key for message queue
    key = ftok("message_queue", 65);

    //create message queue
    message_id = msgget(key, 0666 | IPC_CREAT);

    //check for errors in message queue creation
    if (message_id == -1) {
        printf("Error creating message queue.\n");
        exit(1);
    }

    //fork process to create child process for sending message
    pid_t pid = fork();

    //child process
    if (pid == 0) {
        //get message from user
        printf("Enter message: ");
        fgets(message.message_text, 50, stdin);

        //set message type to 1
        message.message_type = 1;

        //send message to message queue
        msgsnd(message_id, &message, sizeof(message), 0);

        //exit child process
        exit(0);
    }
    //parent process
    else {
        //wait for child process to finish
        wait(NULL);

        //receive message from message queue
        msgrcv(message_id, &message, sizeof(message), 1, 0);

        //print received message
        printf("Received message: %s", message.message_text);

        //remove message queue
        msgctl(message_id, IPC_RMID, NULL);
    }

    return 0;
}