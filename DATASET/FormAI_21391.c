//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 100

typedef struct {
    long mtype;
    char mtext[MSG_SIZE];
} message;

/* Shared message queue ID */
int msgqid;

/* Function to create a message queue */
int create_msg_queue() {
    int id;

    /* Generate a key for the message queue */
    key_t key = ftok(".", 'q');

    /* Create the message queue */
    id = msgget(key, 0666 | IPC_CREAT);

    /* Return the message queue ID */
    return id;
}

/* Function to send a message */
void send_message(char* msg_text) {
    message msg;
    msg.mtype = 1;
    strncpy(msg.mtext, msg_text, MSG_SIZE-1);
    
    /* Send the message */
    if (msgsnd(msgqid, &msg, sizeof(msg)-sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
}

/* Function to receive a message */
void receive_message() {
    message msg;
    
    /* Receive the message */
    if (msgrcv(msgqid, &msg, sizeof(msg)-sizeof(long), 0, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
    
    /* Print the message */
    printf("Received message: %s\n", msg.mtext);
}

/* Main function */
int main(int argc, char* argv[]) {
    pid_t pid;
    
    /* Create the message queue */
    msgqid = create_msg_queue();
    
    /* Fork a child process */
    pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {
        /* Child process */
        printf("Child process is running!\n");
        
        /* Send a message */
        send_message("Hello from the child process!");
        
        /* Exit the child process */
        exit(0);
    }
    else {
        /* Parent process */
        printf("Parent process is running!\n");
        
        /* Wait for the child process to finish */
        wait(NULL);
        
        /* Receive the message */
        receive_message();
    }
    
    /* Remove the message queue */
    msgctl(msgqid, IPC_RMID, NULL);
    
    return 0;
}