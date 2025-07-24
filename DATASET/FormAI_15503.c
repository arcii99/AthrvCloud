//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

// Our program is going to surprise two processes with a secret message.

// We'll start with defining the message structure.
struct my_msg {
    long int msg_type;
    char message[100];
};

int main() {
    // We'll create a message queue for the processes to communicate.
    key_t key = ftok("ipc_example", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct my_msg message;

    // Process 1 starts here.
    if(fork() == 0) {
        printf("Process 1 has started! Sending a surprise message...\n");
        message.msg_type = 1;
        sprintf(message.message, "Surprise, Process 2! Guess what? I'm your twin process!\n");
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Process 1 has sent the message and is now waiting for a reply...\n");

        msgrcv(msgid, &message, sizeof(message), 2, 0);
        printf("Process 1 has received a reply from Process 2: \"%s\"\n", message.message);
        printf("Process 1 is happy and decides to exit...\n");
        exit(0);
    }

    // Process 2 starts here.
    if(fork() == 0) {
        printf("Process 2 has started! Waiting for a surprise message...\n");
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Process 2 has received a surprise message from Process 1: \"%s\"\n", message.message);
        printf("Process 2 is surprised and decides to reply with a secret message...\n");
        message.msg_type = 2;
        sprintf(message.message, "What? No way!!! Where have you been all my life?!\n");
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Process 2 has replied with a secret message. Process 2 is now happy and decides to exit...\n");
        exit(0);
    }

    // Parent process waits for children to finish.
    wait(NULL);
    wait(NULL);
    printf("All processes have completed successfully.\n");

    // We'll now delete the message queue.
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}