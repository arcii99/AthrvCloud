//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Define server address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    // Connect to server
    int connection_status = connect(sock, (struct sockaddr*) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    char message[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);

    if (send(sock, message, strlen(message), 0) == -1) {
        perror("Message sending failed");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
        perror("Message receiving failed");
        exit(EXIT_FAILURE);
    }

    // Print message received from server
    printf("Message received from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}