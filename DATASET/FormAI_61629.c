//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MSG_SIZE 100

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        printf("Failed to create socket...\n");
        exit(0);
    }
    else {
        printf("Socket created successfully...\n");
    }

    struct sockaddr_in server_addr, client_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        printf("Failed to bind socket to port %d...\n", PORT);
        exit(0);
    }
    else {
        printf("Socket bound to port %d...\n", PORT);
    }

    if (listen(sock_fd, 5) < 0) {
        printf("Failed to listen to incoming connections...\n");
        exit(0);
    }
    else {
        printf("Listening to incoming connections...\n");
    }

    socklen_t client_len = sizeof(client_addr);

    int conn_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &client_len);

    if (conn_fd < 0) {
        printf("Failed to establish connection with client...\n");
        exit(0);
    }
    else {
        printf("Connection established with client...\n");
    }

    char message[MAX_MSG_SIZE];
    char reply[MAX_MSG_SIZE];

    while (1) {
        memset(&message, 0, sizeof(message));
        printf("Enter your message: ");
        fgets(message, MAX_MSG_SIZE, stdin);
        send(conn_fd, message, strlen(message), 0);
        memset(&reply, 0, sizeof(reply));
        recv(conn_fd, reply, MAX_MSG_SIZE, 0);
        printf("Client says: %s\n", reply);

        if (strncmp("bye", message, 3) == 0) {
            printf("Closing connection...\n");
            break;
        }
    }

    close(sock_fd);
    close(conn_fd);

    return 0;
}