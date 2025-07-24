//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long int message_type;
    char text[100];
};

int main() {
    // Generate unique key for message queue
    key_t key = ftok("interprocess_communication", 'a');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    int message_queue_id = msgget(key, 0666 | IPC_CREAT);
    if (message_queue_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process - receive message from parent
        struct message received_message;
        if (msgrcv(message_queue_id, &received_message, sizeof(struct message), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Child received message: %s\n", received_message.text);

        // Send reply message to parent
        struct message reply_message = {
            .message_type = 2,
            .text = "Hello from child!"
        };

        if (msgsnd(message_queue_id, &reply_message, sizeof(struct message), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        // Parent process - send message to child
        struct message sent_message = {
            .message_type = 1,
            .text = "Hello from parent!"
        };

        if (msgsnd(message_queue_id, &sent_message, sizeof(struct message), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        // Receive reply message from child
        struct message received_message;
        if (msgrcv(message_queue_id, &received_message, sizeof(struct message), 2, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Parent received reply message: %s\n", received_message.text);

        // Cleanup message queue
        if (msgctl(message_queue_id, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
}