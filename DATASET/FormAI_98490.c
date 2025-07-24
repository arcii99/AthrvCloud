//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define MAX_BUFFER_LENGTH 1024

void error_handler(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_ip = argv[1];

    // Create socket
    int smtp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (smtp_socket == -1) error_handler("Failed to create socket");

    // Create server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(smtp_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
        error_handler("Failed to connect to server");

    printf("Connected to server at %s:%d\n", inet_ntoa(server_address.sin_addr), SERVER_PORT);

    // Receive greeting from server
    char buffer[MAX_BUFFER_LENGTH];
    memset(buffer, 0, sizeof(buffer));
    if (recv(smtp_socket, buffer, sizeof(buffer) - 1, 0) == -1)
        error_handler("Failed to receive greeting");

    printf("Server says: %s", buffer);

    // Send HELLO command
    char hello_message[MAX_BUFFER_LENGTH];
    sprintf(hello_message, "HELLO %s\r\n", server_ip);
    if (send(smtp_socket, hello_message, strlen(hello_message), 0) == -1)
        error_handler("Failed to send HELLO command");

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(smtp_socket, buffer, sizeof(buffer) - 1, 0) == -1)
        error_handler("Failed to receive response to HELLO command");

    printf("Server says: %s", buffer);

    // Send QUIT command
    char quit_message[MAX_BUFFER_LENGTH];
    sprintf(quit_message, "QUIT\r\n");
    if (send(smtp_socket, quit_message, strlen(quit_message), 0) == -1)
        error_handler("Failed to send QUIT command");

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(smtp_socket, buffer, sizeof(buffer) - 1, 0) == -1)
        error_handler("Failed to receive response to QUIT command");

    printf("Server says: %s", buffer);

    // Close socket
    close(smtp_socket);

    return 0;
}