//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the user input hostname
    if (argc != 2) {
        printf("Usage: %s [hostname]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create a socket");
        return EXIT_FAILURE;
    }

    // Convert hostname to IP address using DNS lookup
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(SMTP_PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to the server");
        return EXIT_FAILURE;
    }

    // Receive a welcome message from the server
    char buffer[BUFFER_SIZE] = {0};
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Send a HELO command to identify yourself
    char hello_command[BUFFER_SIZE] = "HELO 127.0.0.1\r\n";
    if (send(client_socket, hello_command, strlen(hello_command), 0) == -1) {
        perror("Failed to send data to the server");
        return EXIT_FAILURE;
    }
    printf("Client: %s", hello_command);

    // Receive a reply from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Send a MAIL FROM command
    char mail_command[BUFFER_SIZE] = "MAIL FROM:<sender@example.com>\r\n";
    if (send(client_socket, mail_command, strlen(mail_command), 0) == -1) {
        perror("Failed to send data to the server");
        return EXIT_FAILURE;
    }
    printf("Client: %s", mail_command);

    // Receive a reply from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Send a RCPT TO command
    char rcpt_command[BUFFER_SIZE] = "RCPT TO:<receiver@example.com>\r\n";
    if (send(client_socket, rcpt_command, strlen(rcpt_command), 0) == -1) {
        perror("Failed to send data to the server");
        return EXIT_FAILURE;
    }
    printf("Client: %s", rcpt_command);

    // Receive a reply from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Send a DATA command to start sending the email
    char data_command[BUFFER_SIZE] = "DATA\r\n";
    if (send(client_socket, data_command, strlen(data_command), 0) == -1) {
        perror("Failed to send data to the server");
        return EXIT_FAILURE;
    }
    printf("Client: %s", data_command);

    // Receive a reply from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Send the email contents
    char email_contents[BUFFER_SIZE] = "From: sender@example.com\r\nTo: receiver@example.com\r\nSubject: Test email\r\n\r\nThis is a test email\r\n.\r\n";
    if (send(client_socket, email_contents, strlen(email_contents), 0) == -1) {
        perror("Failed to send data to the server");
        return EXIT_FAILURE;
    }
    printf("Client: %s", email_contents);

    // Receive a final reply from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Send a QUIT command to terminate the session
    char quit_command[BUFFER_SIZE] = "QUIT\r\n";
    if (send(client_socket, quit_command, strlen(quit_command), 0) == -1) {
        perror("Failed to send data to the server");
        return EXIT_FAILURE;
    }
    printf("Client: %s", quit_command);

    // Receive a reply from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive data from the server");
        return EXIT_FAILURE;
    }
    printf("Server: %s", buffer);

    // Close the socket
    close(client_socket);

    return EXIT_SUCCESS;
}