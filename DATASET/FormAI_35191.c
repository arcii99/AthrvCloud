//FormAI DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1" // IP address of server
#define SERVER_PORT 8080 // Port number of server

int main(int argc, char *argv[]) {
    int sock = 0, status = 0;
    struct sockaddr_in server_addr;
    char message[100] = "Hello, Server! This is Client.";

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to create socket");
        return 1;
    }

    // specify server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address or address not supported");
        return 1;
    }

    // connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection failed");
        return 1;
    }

    // send message to server
    status = send(sock, message, strlen(message), 0);
    if (status < 0) {
        printf("\nFailed to send message");
        return 1;
    }

    printf("Message sent to server: %s\n", message);

    close(sock);
    return 0;
}