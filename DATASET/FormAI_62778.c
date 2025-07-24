//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

// Define a Message Struct
struct message {
    long mtype;
    char mtext[100];
};

void childProcess();
void parentProcess();
void sendMessage(int qid, struct message *msg);
void readMessage(int qid, struct message *msg, long type);

int main() {
    pid_t pid;
    int qid;
    key_t key;
    struct message msg;

    // Generate unique key for message queue
    key = ftok(".", 'q');

    // Create a message queue
    qid = msgget(key, IPC_CREAT | 0660);

    // Fork a child process
    pid = fork();

    if(pid == 0) {
        // Child process
        childProcess();
    } else if(pid == -1) {
        // Error
        printf("Error attempting to fork child process.\n");
        exit(1);
    } else {
        // Parent process
        parentProcess();
    }

    // Destroy the message queue
    msgctl(qid, IPC_RMID, NULL);

    return 0;
}

void childProcess() {
    int qid;
    key_t key;
    struct message msg;

    // Generate the same key used by the parent
    key = ftok(".", 'q');

    // Get the message queue created by the parent
    qid = msgget(key, 0);

    // Receive message from parent
    readMessage(qid, &msg, 1);

    // Modify the message text and send it back to parent
    strcat(msg.mtext, " - modified by child process");
    sendMessage(qid, &msg);

    exit(0);
}

void parentProcess() {
    int qid;
    key_t key;
    struct message msg;

    // Generate the unique key used by both parent and child
    key = ftok(".", 'q');

    // Construct a message to send to the child
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello from parent process");

    // Send the message to the child
    sendMessage(qid, &msg);

    // Wait for a response from the child
    readMessage(qid, &msg, 2);

    // Output the modified message received from child
    printf("%s\n", msg.mtext);
}

void sendMessage(int qid, struct message *msg) {
    // Send message to message queue
    msgsnd(qid, msg, strlen(msg->mtext)+1, 0);
}

void readMessage(int qid, struct message *msg, long type) {
    // Receive message from message queue
    msgrcv(qid, msg, sizeof(msg->mtext), type, 0);
}