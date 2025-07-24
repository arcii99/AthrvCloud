//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    // Create a socket to communicate with the server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Define the server address and port number
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    char message[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);

    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Receive data from the server
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);

    printf("Server response: %s\n", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}