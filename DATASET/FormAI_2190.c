//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char command[BUFFER_SIZE], buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-ip> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Error setting server address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message from server
    if ((bytes_received = read(client_socket, buffer, BUFFER_SIZE)) < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send username to server
    sprintf(command, "USER %s\r\n", argv[2]);
    if (write(client_socket, command, strlen(command)) < 0) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    if ((bytes_received = read(client_socket, buffer, BUFFER_SIZE)) < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send password to server
    printf("Enter your password: ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove trailing newline
    sprintf(command, "PASS %s\r\n", command);
    if (write(client_socket, command, strlen(command)) < 0) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    if ((bytes_received = read(client_socket, buffer, BUFFER_SIZE)) < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send LIST command to server
    sprintf(command, "LIST\r\n");
    if (write(client_socket, command, strlen(command)) < 0) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    if ((bytes_received = read(client_socket, buffer, BUFFER_SIZE)) < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Disconnect from server
    if (write(client_socket, "QUIT\r\n", strlen("QUIT\r\n")) < 0) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }

    // Close socket
    if (close(client_socket) < 0) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }

    return 0;
}