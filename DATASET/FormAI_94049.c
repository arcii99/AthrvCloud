//FormAI DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 8888

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);
    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 1) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT_NUMBER);

    // Accept incoming connection
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket == -1) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    char *client_ip_address = inet_ntoa(client_address.sin_addr);
    printf("Client %s:%d connected.\n", client_ip_address, ntohs(client_address.sin_port));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("Failed to receive data");
            exit(EXIT_FAILURE);
        }

        if (bytes_received == 0) {
            printf("Client %s:%d disconnected.\n", client_ip_address, ntohs(client_address.sin_port));
            break;
        }

        printf("Received %d bytes of data from client %s:%d:\n%s", bytes_received, client_ip_address, ntohs(client_address.sin_port), buffer);

        char *response = "Data received successfully.\n";
        int bytes_sent = send(client_socket, response, strlen(response), 0);
        if (bytes_sent == -1) {
            perror("Failed to send data");
            exit(EXIT_FAILURE);
        }
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}