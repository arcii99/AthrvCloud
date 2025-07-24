//FormAI DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {

    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Failed to create socket!\n");
        return EXIT_FAILURE;
    }
    printf("Socket created successfully!\n");

    // Create the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Connection failed!\n");
        return EXIT_FAILURE;
    }
    printf("Connected to server!\n");

    // Send message to the server
    char *message = "Hello from the client!";
    if (send(client_socket, message, strlen(message), 0) == -1) {
        printf("Error: Failed to send message!\n");
        return EXIT_FAILURE;
    }
    printf("Message sent to server: %s\n", message);

    // Receive message from the server
    char buffer[MAX_BUFFER] = {0};
    if (read(client_socket, buffer, MAX_BUFFER) == -1) {
        printf("Error: Failed to receive message!\n");
        return EXIT_FAILURE;
    }
    printf("Message received from server: %s\n", buffer);

    // Close the socket
    close(client_socket);
    printf("Connection closed!\n");

    return EXIT_SUCCESS;
}