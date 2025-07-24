//FormAI DATASET v1.0 Category: Socket programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int socketfd;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};

    // Creating the socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Assigning the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return EXIT_FAILURE;
    }

    // Connecting to the server
    if (connect(socketfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    // Sending message to server
    char *message = "Hello, server!";
    send(socketfd, message, strlen(message), 0);
    printf("Message sent to server!\n");

    // Receiving response from the server
    int valread = read(socketfd, buffer, 1024);
    printf("Server response: %s\n", buffer);

    // Closing the socket file descriptor
    close(socketfd);

    return 0;
}