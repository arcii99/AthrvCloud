//FormAI DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 512
#define MSG_KEY1 1234
#define MSG_KEY2 5678

struct message {
    long int msg_type;
    char msg_text[MAX_TEXT];
};

int main() {
    pid_t pid;

    // Creating message queues
    int msg_id1 = msgget(MSG_KEY1, 0666 | IPC_CREAT);
    int msg_id2 = msgget(MSG_KEY2, 0666 | IPC_CREAT);

    if (msg_id1 == -1) {
        perror("Error in creating message queue");
        exit(EXIT_FAILURE);
    }

    if (msg_id2 == -1) {
        perror("Error in creating message queue");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    
    if (pid == -1) {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) {
        // Child process
        struct message message1, message2;

        // Receiving message from parent
        if (msgrcv(msg_id1, &message1, MAX_TEXT, 1, 0) == -1) {
            perror("Error in receiving message from parent");
            exit(EXIT_FAILURE);
        }

        printf("Child: Received message from parent: %s\n", message1.msg_text);

        // Sending message to parent
        sprintf(message2.msg_text, "Hello from child");
        message2.msg_type = 2;

        if (msgsnd(msg_id2, &message2, sizeof(message2.msg_text), 0) == -1) {
            perror("Error in sending message to parent");
            exit(EXIT_FAILURE);
        }

        printf("Child: Sent message to parent\n");

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        struct message message1, message2;

        // Sending message to child
        sprintf(message1.msg_text, "Hello from parent");
        message1.msg_type = 1;

        if (msgsnd(msg_id1, &message1, sizeof(message1.msg_text), 0) == -1) {
            perror("Error in sending message to child");
            exit(EXIT_FAILURE);
        }

        printf("Parent: Sent message to child\n");

        // Receiving message from child
        if (msgrcv(msg_id2, &message2, MAX_TEXT, 2, 0) == -1) {
            perror("Error in receiving message from child");
            exit(EXIT_FAILURE);
        }

        printf("Parent: Received message from child: %s\n", message2.msg_text);
    }

    return 0;
}