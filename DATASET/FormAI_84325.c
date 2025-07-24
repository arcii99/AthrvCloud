//FormAI DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 25

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: ./client <server-ip> <email-to>\n");
        return 1;
    }
    char *server_ip = argv[1];
    char *email_to = argv[2];

    char buffer[BUFFER_SIZE];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("Invalid server IP address");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Receive the server greeting
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }
    printf("Server greeting: %s\n", buffer);

    // Send the HELO/EHLO command
    char *hostname = "<client-hostname>";
    sprintf(buffer, "HELO %s\r\n", hostname);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending HELO command");
        return 1;
    }

    // Receive the server response to HELO/EHLO
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }
    printf("Server response to HELO: %s\n", buffer);

    // Send the MAIL FROM command
    char *email_from = "<client-email>";
    sprintf(buffer, "MAIL FROM: <%s>\r\n", email_from);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending MAIL FROM command");
        return 1;
    }

    // Receive the server response to MAIL FROM
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }
    printf("Server response to MAIL FROM: %s\n", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", email_to);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending RCPT TO command");
        return 1;
    }

    // Receive the server response to RCPT TO
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }
    printf("Server response to RCPT TO: %s\n", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending DATA command");
        return 1;
    }

    // Receive the server response to DATA
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }
    printf("Server response to DATA: %s\n", buffer);

    // Send the email message
    sprintf(buffer, "Subject: Test Email\r\n\r\nThis is a test email sent using the C email client.");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending email message");
        return 1;
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending QUIT command");
        return 1;
    }

    // Receive the server response to QUIT
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }
    printf("Server response to QUIT: %s\n", buffer);

    close(sockfd);
    return 0;
}