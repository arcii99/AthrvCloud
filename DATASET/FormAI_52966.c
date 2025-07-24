//FormAI DATASET v1.0 Category: Client Server Application ; Style: future-proof
// A simple chat program between client and server
// Future-proofed with dynamic memory allocation and pthreads

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_MSG_LEN 100

void *read_msgs(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char msg[MAX_MSG_LEN];
    while(1) {
        if(recv(sock, msg, MAX_MSG_LEN, 0) > 0) {
            printf("Server: %s\n", msg);
        }
    }
}

int main(int argc, char const *argv[]) {
    int sock_desc;
    struct sockaddr_in server_addr;
    char msg[MAX_MSG_LEN];

    // Create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if(connect(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    // Create a new thread to read incoming messages from server
    pthread_t recv_thread;
    if(pthread_create(&recv_thread, NULL, read_msgs, (void *)&sock_desc) < 0) {
        printf("Failed to create thread\n");
    }

    // Read and send messages from client to server
    while(1) {
        printf("Client: ");
        fgets(msg, MAX_MSG_LEN, stdin);
        send(sock_desc, msg, strlen(msg), 0);
        memset(msg, 0, MAX_MSG_LEN);
    }

    return 0;
}