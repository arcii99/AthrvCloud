//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
/*
 * C Networking Example Program
 * 
 * This program demonstrates a simple TCP server-client communication using BSD sockets.
 * The server listens for incoming connections and sends a message to the client. The client
 * receives the message and sends a reply back to the server. 
 * 
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options to socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address info
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind server to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send a message to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent to client\n");

    // Receive a message from the client
    valread = read(new_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    // Reply to message from client
    char *reply = "Message received by server";
    send(new_socket, reply, strlen(reply), 0);
    printf("Reply message sent to client\n");

    return 0;
}