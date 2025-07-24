//FormAI DATASET v1.0 Category: Socket programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_fd, client_socket, read_value;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(server_address);
    char hello_message[] = "Hello from the other side!";
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket to address
    if (bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    while (1) {
        // Accepting incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *) &client_address, (socklen_t *) &address_length)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connection established with IP address: %s and port: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Sending hello message to client
        send(client_socket, hello_message, strlen(hello_message), 0);

        // Receiving message from client
        read_value = read(client_socket, buffer, 1024);
        printf("Client message received: %s\n", buffer);

        // Closing connection with client
        close(client_socket);
    }

    return 0;
}