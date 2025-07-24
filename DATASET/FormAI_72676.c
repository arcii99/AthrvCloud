//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int connect_to_server(char *server_address, int port) {
    int client_socket;
    struct sockaddr_in server;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Could not create socket");
        exit(1);
    }

    // Set server details
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Unable to connect to server");
        exit(1);
    }

    return client_socket;
}

void send_email(int client_socket, char *sender, char *recipient, char *subject, char *message) {
    char buffer[BUFFER_SIZE];
    int bytes_sent;

    // Send HELO command
    sprintf(buffer, "HELO client\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Send email content
    sprintf(buffer, "From: <%s>\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);

    sprintf(buffer, "To: <%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);

    sprintf(buffer, "Subject: %s\r\n", subject);
    send(client_socket, buffer, strlen(buffer), 0);

    sprintf(buffer, "\r\n%s\r\n.\r\n", message);
    send(client_socket, buffer, strlen(buffer), 0);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Close connection
    close(client_socket);

    printf("Email sent successfully!\n");
}

int main(int argc, char *argv[]) {
    int client_socket;
    int port = 25;
    char sender[50];
    char recipient[50];
    char subject[256];
    char message[BUFFER_SIZE];

    // Prompt user for sender email address
    printf("Enter sender email address: ");
    fgets(sender, 50, stdin);
    // Remove newline character from input string
    sender[strcspn(sender, "\n")] = 0;

    // Prompt user for recipient email address
    printf("Enter recipient email address: ");
    fgets(recipient, 50, stdin);
    recipient[strcspn(recipient, "\n")] = 0;

    // Prompt user for email subject
    printf("Enter email subject: ");
    fgets(subject, 256, stdin);
    subject[strcspn(subject, "\n")] = 0;

    // Prompt user for email message
    printf("Enter email message (max %d characters):\n", BUFFER_SIZE);
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    // Connect to SMTP server
    client_socket = connect_to_server("smtp.gmail.com", port);

    // Send email
    send_email(client_socket, sender, recipient, subject, message);

    return 0;
}