//FormAI DATASET v1.0 Category: Email Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024 // Max buffer size for receiving email data

void send_email(int socket, char* from, char* to, char* subject, char* body) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE); // Clear the buffer

    // Send the FROM address
    sprintf(buffer, "MAIL FROM:<%s>\n", from);
    send(socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    // Send the TO address
    sprintf(buffer, "RCPT TO:<%s>\n", to);
    send(socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    // Send the email data
    send(socket, "DATA\n", strlen("DATA\n"), 0);
    sprintf(buffer, "From: <%s>\nTo: <%s>\nSubject: %s\n\n%s\n.\n", from, to, subject, body);
    send(socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    // Close the connection
    send(socket, "QUIT\n", strlen("QUIT\n"), 0);
    close(socket);
}

int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc < 5) {
        printf("Usage: %s <server_ip> <from_address> <to_address> <subject> <body>\n", argv[0]);
        return 1;
    }

    // Parse the arguments
    char* server_ip = argv[1];
    char* from_address = argv[2];
    char* to_address = argv[3];
    char* subject = argv[4];
    char* body = argv[5];

    // Create the server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(25);

    // Create a TCP socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Send the email
    send_email(socket_fd, from_address, to_address, subject, body);

    return 0;
}