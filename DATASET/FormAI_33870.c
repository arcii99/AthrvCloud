//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char buf[BUF_SIZE];
    int byte_count;

    // Create socket
    server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock < 0) {
        perror("ERROR: Cannot create socket");
        exit(1);
    }

    // Bind socket to IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    server_addr.sin_port = htons(7890); // random port number
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR: Cannot bind socket");
        exit(1);
    }

    // Listen for incoming connection requests
    if (listen(server_sock, 5) < 0) {
        perror("ERROR: Cannot listen on socket");
        exit(1);
    }

    printf("Waiting for incoming connections...\n");

    // Accept incoming connection request
    client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_sock < 0) {
        perror("ERROR: Cannot accept connection");
        exit(1);
    }

    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive message from client
    byte_count = recv(client_sock, buf, sizeof(buf), 0);
    if (byte_count < 0) {
        perror("ERROR: Cannot receive data");
        exit(1);
    }

    printf("Received message: %s\n", buf);

    // Convert message to uppercase
    for (int i = 0; i < byte_count; ++i) {
        buf[i] = toupper(buf[i]);
    }

    // Send message back to client
    byte_count = send(client_sock, buf, byte_count, 0);
    if (byte_count < 0) {
        perror("ERROR: Cannot send data");
        exit(1);
    }

    // Close client socket
    close(client_sock);

    // Close server socket
    close(server_sock);

    return 0;
}