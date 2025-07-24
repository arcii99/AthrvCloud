//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    struct sockaddr_in server_address, client_address;
    int server_fd, new_socket, val_read;
    char buffer[BUFFER_SIZE] = {0};
    char response[] = "I received your message!";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while(1) {

        // Accepting new connection
        int client_address_size = sizeof(client_address);
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_size)) < 0) {
            perror("Accepting connection failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receiving client message
        val_read = read(new_socket, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);

        // Sending response message
        send(new_socket, response, strlen(response), 0);
        printf("Response sent successfully!\n");

        // Closing the socket
        close(new_socket);
        printf("Client disconnected\n");
    }

    return 0;
}