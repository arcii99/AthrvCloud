//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    char *server_ip = "mail.example.com";
    char *from_email = "sender@example.com";
    char *to_email = "recipient@example.com";
    char *subject = "Test Email";
    char *message = "Hello, this is a test email.";
    char buffer[BUFFER_SIZE];
    int socket_desc;
    struct sockaddr_in server;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    // Set server details
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(25); // SMTP port

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error\n");
        return 1;
    }

    // Read server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error reading server response\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send EHLO command
    sprintf(buffer, "EHLO %s\r\n", from_email);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending EHLO command\n");
        return 1;
    }

    // Read server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error reading server response\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_email);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending MAIL FROM command\n");
        return 1;
    }

    // Read server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error reading server response\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to_email);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending RCPT TO command\n");
        return 1;
    }

    // Read server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error reading server response\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending DATA command\n");
        return 1;
    }

    // Read server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error reading server response\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send email header
    sprintf(buffer, "From: <%s>\r\n", from_email);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending email header\n");
        return 1;
    }

    sprintf(buffer, "To: <%s>\r\n", to_email);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending email header\n");
        return 1;
    }

    sprintf(buffer, "Subject: %s\r\n\r\n", subject);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending email header\n");
        return 1;
    }

    // Send email message
    sprintf(buffer, "%s\r\n.", message);
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending email message\n");
        return 1;
    }

    // Read server response
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error reading server response\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("Error sending QUIT command\n");
        return 1;
    }

    // Close socket
    close(socket_desc);

    return 0;
}