//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct message {
    long int message_type;
    char message_text[MAX_TEXT];
};

int main()
{
    struct message data;
    int message_queue_id;
    key_t queue_key;

    // Generate a unique key for the message queue
    queue_key = ftok(".", 'm');

    // Create the message queue with permission 0666
    message_queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    if (message_queue_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Enter message: ");
    fgets(data.message_text, MAX_TEXT, stdin);

    // Add message to the message queue with type 1
    data.message_type = 1;
    if (msgsnd(message_queue_id, &data, MAX_TEXT, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    // Read message from the message queue with type 2
    if (msgrcv(message_queue_id, &data, MAX_TEXT, 2, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s", data.message_text);

    // Remove the message queue
    if (msgctl(message_queue_id, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}