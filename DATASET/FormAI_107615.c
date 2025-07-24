//FormAI DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9000
#define MAX_CONN 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Create variables for the server socket, client socket and addresses
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];

    // Create the server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address struct properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);
    memset(&(server_address.sin_zero), 0, 8);

    // Bind the server socket
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_sockfd, MAX_CONN) == -1) {
        perror("Error listening for client connections");
        exit(EXIT_FAILURE);
    }

    // Accept client connections and handle them individually
    while (1) {
        client_len = sizeof(client_address);
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len)) == -1) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        printf("Connected to client: %s\n", inet_ntoa(client_address.sin_addr));

        // Read data from client socket
        int bytes_read = read(client_sockfd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        printf("Data Received: %s\n", buffer);

        // Send response back to client socket
        char response[] = "ACKNOWLEDGED";
        if (send(client_sockfd, response, strlen(response), 0) == -1) {
            perror("Error sending response to client socket");
            close(client_sockfd);
            exit(EXIT_FAILURE);
        }

        // Close client socket
        close(client_sockfd);
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}