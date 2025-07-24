//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Creating a TCP socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("192.168.1.1"); // Replace with the SMTP server IP address

    // Connecting to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE] = {0};

    // Receiving the server greeting
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending the HELO command
    char helo_command[MAX_BUFFER_SIZE];
    sprintf(helo_command, "HELO %s\r\n", "example.com"); // Replace with your domain name
    if (send(client_socket, helo_command, strlen(helo_command), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the server response
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending the MAIL FROM command
    char mail_from_command[MAX_BUFFER_SIZE];
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", "sender@example.com"); // Replace with the sender's email address
    if (send(client_socket, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the server response
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending the RCPT TO command
    char rcpt_to_command[MAX_BUFFER_SIZE];
    sprintf(rcpt_to_command, "RCPT TO:<%s>\r\n", "recipient@example.com"); // Replace with the recipient's email address
    if (send(client_socket, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the server response
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending the DATA command
    if (send(client_socket, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the server response
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending the message body
    char message_body[MAX_BUFFER_SIZE];
    sprintf(message_body, "From: %s\r\nTo: %s\r\nSubject: Test Email\r\n\r\nThis is a test email sent using a SMTP client.\r\n.\r\n",
            "sender@example.com", "recipient@example.com"); // Replace with appropriate email addresses and message body
    if (send(client_socket, message_body, strlen(message_body), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the server response
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending the QUIT command
    if (send(client_socket, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the server response
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Closing the socket
    close(client_socket);

    return 0;
}