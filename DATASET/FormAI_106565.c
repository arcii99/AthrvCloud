//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8888
#define BUFF_SIZE 1024

int main() {
    int socket_fd; // socket file descriptor
    struct sockaddr_in server_addr; // server address
    char buffer[BUFF_SIZE]; // buffer for sending and receiving data
    int nbytes;

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address structure values, including the port number and IP address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) < 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Making a connection to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Sending a message to the server
    char message[] = "Hello, I am a client!";
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }

    // Receiving a message back from the server
    if ((nbytes = read(socket_fd, buffer, BUFF_SIZE)) < 0) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }

    // Displaying the received message
    printf("Received message from server: %s\n", buffer);

    // Closing the connection
    close(socket_fd);
    return 0;
}