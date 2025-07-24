//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

struct message_buffer
{
    long message_type;
    char message[MSG_SIZE];
};

int main()
{
    struct message_buffer message;
    key_t key;
    int message_id;
    pid_t pid = getpid();

    // generate a unique key
    key = ftok("progfile", 65);

    // create a message queue
    message_id = msgget(key, 0666 | IPC_CREAT);

    if (message_id == -1)
    {
        printf("Failed to create message queue.\n");
        exit(1);
    }

    printf("Process %ld has created a message queue with id %d.\n", (long)pid, message_id);

    // send a message to the queue
    message.message_type = 1;
    strcpy(message.message, "Hello from process A.");
    msgsnd(message_id, &message, sizeof(message), 0);
    printf("Process %ld has sent a message to process B.\n", (long)pid);

    // receive a message from the queue
    msgrcv(message_id, &message, sizeof(message), 2, 0);
    printf("Process %ld has received a message from process B: %s\n", (long)pid, message.message);

    // remove the message queue
    msgctl(message_id, IPC_RMID, NULL);
    printf("Process %ld has removed the message queue with id %d.\n", (long)pid, message_id);

    // exit the program
    exit(0);
}