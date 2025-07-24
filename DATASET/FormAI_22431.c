//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_SIZE 1024

struct message { 
    long msg_type; 
    char msg_text[MAX_SIZE]; 
};

void child_process(void);
void parent_process(void);

int main(void) {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("Failed to create child process");
        exit(1);
    } else if (pid == 0) {
        child_process();
    } else {
        parent_process();
    }

    return 0;
}

void child_process(void) {
    key_t key;
    int msg_id;
    struct message msg;
    char buffer[MAX_SIZE];

    memset(buffer, 0, sizeof(buffer));

    key = ftok("ipc_example", 'M');
    if (key == -1) {
        perror("Failed to generate key");
        exit(1);
    }

    msg_id = msgget(key, IPC_CREAT | 0666);
    if (msg_id == -1) {
        perror("Failed to create message queue");
        exit(1);
    }

    printf("Child process waiting for message...\n");

    if (msgrcv(msg_id, &msg, MAX_SIZE, 1, 0) == -1) {
        perror("Failed to receive message");
        exit(1);
    }

    printf("Child process received message: %s\n", msg.msg_text);

    snprintf(buffer, sizeof(buffer), "Hello, %s! I am your child.\n", msg.msg_text);
    strncpy(msg.msg_text, buffer, MAX_SIZE);

    msg.msg_type = 2;

    if (msgsnd(msg_id, &msg, strlen(msg.msg_text) + 1, 0) == -1) {
        perror("Failed to send message");
        exit(1);
    }

    printf("Child process sent message: %s\n", msg.msg_text);
}

void parent_process(void) {
    key_t key;
    int msg_id;
    struct message msg;
    char input[MAX_SIZE];

    printf("Parent process waiting for input...\n");

    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character from input

    key = ftok("ipc_example", 'M');
    if (key == -1) {
        perror("Failed to generate key");
        exit(1);
    }

    msg_id = msgget(key, IPC_CREAT | 0666);
    if (msg_id == -1) {
        perror("Failed to create message queue");
        exit(1);
    }
    
    strncpy(msg.msg_text, input, MAX_SIZE);
    msg.msg_type = 1;

    if (msgsnd(msg_id, &msg, strlen(msg.msg_text) + 1, 0) == -1) {
        perror("Failed to send message");
        exit(1);
    }

    printf("Parent process sent message: %s\n", msg.msg_text);

    if (msgrcv(msg_id, &msg, MAX_SIZE, 2, 0) == -1) {
        perror("Failed to receive message");
        exit(1);
    }

    printf("Parent process received message: %s\n", msg.msg_text);
}