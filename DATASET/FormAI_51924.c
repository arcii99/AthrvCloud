//FormAI DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int client_socket = 0;
    struct sockaddr_in server_address;

    // Create client socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Error: Could not create socket \n");
        return -1;
    }

    // Configure server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("\n Error: Invalid address \n");
        return -1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("\n Error: Connection failed \n");
        return -1;
    }

    // Receive welcome message from server
    char welcome_message[BUFFER_SIZE] = {0};
    if (recv(client_socket, welcome_message, BUFFER_SIZE, 0) > 0) {
        printf("%s\n", welcome_message);
    }

    // Send message to server and receive response
    char message[BUFFER_SIZE] = {0};
    while(1) {
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\r\n")] = 0;
        send(client_socket, message, strlen(message), 0);
        if (strcmp(message, "exit") == 0) {
            break;
        }
        char response[BUFFER_SIZE] = {0};
        if (recv(client_socket, response, BUFFER_SIZE, 0) > 0) {
            printf("Server response: %s\n", response);
        }
    }

    // Close client socket
    close(client_socket);

    return 0;
}