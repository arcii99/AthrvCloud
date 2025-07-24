//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
// This is going to be the most exciting C interprocess communication example program you'll ever see!

#include <stdio.h>  // For standard I/O functions
#include <stdlib.h> // For exit()
#include <unistd.h> // For fork() and getpid()
#include <sys/types.h> // For pid_t and key_t
#include <sys/ipc.h>   // For IPC_CREAT, IPC_RMID, and key_t
#include <sys/msg.h>   // For message queue functions
#include <string.h>    // For memset()

#define MSG_SIZE 1024 // The maximum message size

// The message structure
struct message {
    long type;
    char data[MSG_SIZE];
} msg;

int main() {
    printf("Welcome to the exciting world of interprocess communication in C!\n");

    // Generate a unique key for the message queue
    key_t key = ftok("ipc_example", 'a');

    // Create the message queue with the unique key
    int msg_id = msgget(key, IPC_CREAT | 0666);
    if (msg_id == -1) {
        printf("Error creating message queue!\n");
        exit(1);
    }

    // Fork a child process to send a message
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process!\n");
        exit(1);
    } else if (pid == 0) {
        // This is the child process
        strcpy(msg.data, "Hello from the child process!");
        msg.type = 1;
        msgsnd(msg_id, &msg, strlen(msg.data) + 1, 0);
        printf("Child process sent message: %s\n", msg.data);
        exit(0);
    } else {
        // This is the parent process
        sleep(1); // Wait for child process to send message

        // Receive the message from the child process
        memset(msg.data, 0, MSG_SIZE);
        msgrcv(msg_id, &msg, MSG_SIZE, 1, 0);
        printf("Parent process received message: %s\n", msg.data);

        // Destroy the message queue
        msgctl(msg_id, IPC_RMID, NULL);
        printf("Message queue destroyed.\n");
    }

    return 0;
}