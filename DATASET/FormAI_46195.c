//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024

// Message queue struct
struct msgbuf {
    long mtype;
    char mtext[BUF_SIZE];
};

// Global variables
int sock;
pthread_mutex_t mutex;
int msgid;
struct sockaddr_in serv_addr;

// Thread function to handle incoming messages
void *receive_messages(void *arg) {
    while (1) {
        struct msgbuf message;
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("[CLIENT 2]: %s\n", message.mtext);
    }
}

// Function to send message to server
void send_message(char *message) {
    struct msgbuf msg;
    msg.mtype = 1;
    strncpy(msg.mtext, message, BUF_SIZE);
    msgsnd(msgid, &msg, sizeof(msg), 0);
}

// Function to initialize message queue
void init_msg_queue() {
    key_t key = ftok("server.c", 'A');
    msgid = msgget(key, 0666 | IPC_CREAT);
}

// Function to initialize socket connection
void init_connection() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    pthread_t tid;
    char buffer[BUF_SIZE];
    
    // Initialize message queue
    init_msg_queue();

    // Initialize connection
    init_connection();
    
    // Create receive messages thread
    pthread_create(&tid, NULL, receive_messages, NULL);
    
    while (1) {
        printf("[CLIENT 1]: ");
        fgets(buffer, BUF_SIZE, stdin);
        strtok(buffer, "\n"); // Remove newline character
        send_message(buffer);
    }

    return 0;
}