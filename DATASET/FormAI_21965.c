//FormAI DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MESSAGE_SIZE 64

typedef struct message {
    long type;
    char text[MESSAGE_SIZE];
} message_t;

void send_message(int msg_queue_id, long message_type, const char* message_text) {
    message_t message;
    message.type = message_type;
    strncpy(message.text, message_text, MESSAGE_SIZE - 1);
    int send_result = msgsnd(msg_queue_id, &message, sizeof(message_t), 0);
    if (send_result == -1) {
        perror("Error sending message");
    }
}

void receive_message(int msg_queue_id, long message_type, char* buffer) {
    message_t message;
    int receive_result = msgrcv(msg_queue_id, &message, sizeof(message_t), message_type, 0);
    if (receive_result == -1) {
        perror("Error receiving message");
    } else {
        strncpy(buffer, message.text, MESSAGE_SIZE);
    }
}

int create_message_queue(key_t key) {
    int queue_id = msgget(key, IPC_CREAT | 0660);
    if (queue_id == -1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }
    return queue_id;
}

void delete_message_queue(int queue_id) {
    int delete_result = msgctl(queue_id, IPC_RMID, NULL);
    if (delete_result == -1) {
        perror("Error deleting message queue");
    }
}

int main() {
    const key_t MESSAGE_QUEUE_KEY = 1234;
    const long MESSAGE_TYPE_1 = 1;
    const long MESSAGE_TYPE_2 = 2;

    // Create message queue
    int msg_queue_id = create_message_queue(MESSAGE_QUEUE_KEY);

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("Child process (PID=%d) starting...\n", getpid());

        // Wait for a message on queue
        char message_buffer[MESSAGE_SIZE];
        receive_message(msg_queue_id, MESSAGE_TYPE_1, message_buffer);
        printf("Child process received message: %s\n", message_buffer);

        // Send a response message
        send_message(msg_queue_id, MESSAGE_TYPE_2, "Hello from child process!");

        printf("Child process exiting...\n");

        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID=%d) starting...\n", getpid());

        // Send a message to child process
        send_message(msg_queue_id, MESSAGE_TYPE_1, "Hello from parent process!");

        // Wait for a response message from child process
        char message_buffer[MESSAGE_SIZE];
        receive_message(msg_queue_id, MESSAGE_TYPE_2, message_buffer);
        printf("Parent process received message: %s\n", message_buffer);

        // Delete message queue
        delete_message_queue(msg_queue_id);

        printf("Parent process exiting...\n");
    }

    return 0;
}