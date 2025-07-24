//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

// Define message structure
struct message {
    long int msg_type;
    char msg_text[100];
};

int main() {

    // Create a message queue
    int q_id = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (q_id == -1) {
        fprintf(stderr, "msgget failed");
        exit(EXIT_FAILURE);
    }

    int running = 1;
    struct message received_msg;

    while (running) {
        // Receive new messages from the queue
        if (msgrcv(q_id, (void *)&received_msg, sizeof(received_msg.msg_text), 0, 0) == -1) {
            fprintf(stderr, "msgrcv failed");
            exit(EXIT_FAILURE);
        }

        // Print the received message and prompt for a response
        printf("Message received: %s\n", received_msg.msg_text);
        printf("Enter response (q to quit): ");

        // Read user input
        char response[100];
        fgets(response, sizeof(response), stdin);

        // Check if user wants to quit
        if (strncmp(response, "q", 1) == 0) {
            running = 0;
        }

        else {
            // Send response message to the queue
            struct message response_msg;
            response_msg.msg_type = 1; // set the message type to 1
            strcpy(response_msg.msg_text, response);
            if (msgsnd(q_id, (void *)&response_msg, sizeof(response_msg.msg_text), 0) == -1) {
                fprintf(stderr, "msgsnd failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Delete the message queue
    if (msgctl(q_id, IPC_RMID, 0) == -1) {
        fprintf(stderr, "msgctl(IPC_RMID) failed");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}