//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socketfd;
    struct sockaddr_in server_addr;
    char message[1000], buffer[1024];
    int port = 8080;

    // Create Socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if (socketfd < 0) {
        perror("Could not create socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to Server
    if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to Server...\n");

    while (1) {
        printf("Enter a message: ");
        fgets(message, 1000, stdin);

        // Send message to Server
        if (send(socketfd, message, strlen(message), 0) < 0) {
            perror("Send failed");
            return 1;
        }

        // Receive message from Server
        if (recv(socketfd, buffer, 1024, 0) < 0) {
            perror("Receive failed");
            return 1;
        }

        printf("Server: %s\n", buffer);
    }

    // Close Socket
    close(socketfd);

    return 0;
}