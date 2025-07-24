//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    printf("Welcome to my cheerful TCP/IP programming example!\n");
    printf("Let's send a message from one client to another using sockets.\n");

    // create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Client socket created successfully!\n");

    // specify the address of the server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server successfully!\n");

    // send a message to the server
    char message[BUFFER_SIZE];
    printf("Enter your message: ");
    fgets(message, BUFFER_SIZE, stdin);
    if (send(client_socket, message, strlen(message), 0) == -1) {
        printf("Failed to send message\n");
        exit(EXIT_FAILURE);
    }
    printf("Message sent successfully to server!\n");

    // receive the message from the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive message\n");
        exit(EXIT_FAILURE);
    }
    printf("Message from server: %s\n", buffer);

    // close the client socket
    close(client_socket);
    printf("Socket closed successfully!\n");

    printf("Thank you for using my program!\n");
    return 0;
}