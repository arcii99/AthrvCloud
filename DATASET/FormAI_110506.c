//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int client_socket = 0;
    struct sockaddr_in server_addr;

    char buffer[1024] = {0};
    char message[] = "Hello server";

    // Create the socket
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        return -1;
    }

    // Set the server address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }

    // Connect to the server
    if(connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }

    // Send the message to server
    send(client_socket, message, strlen(message), 0);

    printf("Message sent to server: %s\n", message);

    // Receive the response from server and print it
    read(client_socket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}