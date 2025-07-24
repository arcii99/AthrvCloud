//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char hostname[100];
    char sender_email[100];
    char recipient_email[100];
    char subject[100];
    char body[500];
} Email;

void send_email(Email email);

int main(int argc, char const *argv[]) {
    Email email;

    strcpy(email.hostname, "mail.example.com");
    strcpy(email.sender_email, "sender@example.com");
    strcpy(email.recipient_email, "recipient@example.com");
    strcpy(email.subject, "Test Email");
    strcpy(email.body, "This is a test email sent from a SMTP client.");

    send_email(email);

    return 0;
}

void send_email(Email email) {
    struct hostent *host;
    struct sockaddr_in server_socket;
    char message[MAX_BUFFER_SIZE];

    // Get server IP address
    if ((host = gethostbyname(email.hostname)) == NULL) {
        perror("gethostbyname failed");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set server info
    bzero(&server_socket, sizeof(server_socket));
    server_socket.sin_family = AF_INET;
    server_socket.sin_port = htons(25);
    server_socket.sin_addr = *((struct in_addr*) host->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_socket, sizeof(server_socket)) < 0) {
        perror("connection failed");
        exit(1);
    }

    // Receive server response
    bzero(message, MAX_BUFFER_SIZE);
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "220 example.com ESMTP"

    // Send HELO command
    sprintf(message, "HELO %s\r\n", email.hostname);
    send(sockfd, message, strlen(message), 0);

    // Receive server response
    bzero(message, MAX_BUFFER_SIZE);
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "250 OK"

    // Send MAIL FROM command
    sprintf(message, "MAIL FROM: <%s>\r\n", email.sender_email);
    send(sockfd, message, strlen(message), 0);

    // Receive server response
    bzero(message, MAX_BUFFER_SIZE);
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "250 OK"

    // Send RCPT TO command
    sprintf(message, "RCPT TO: <%s>\r\n", email.recipient_email);
    send(sockfd, message, strlen(message), 0);

    // Receive server response
    bzero(message, MAX_BUFFER_SIZE);
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "250 OK"

    // Send DATA command
    sprintf(message, "DATA\r\n");
    send(sockfd, message, strlen(message), 0);

    // Receive server response
    bzero(message, MAX_BUFFER_SIZE);
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "354 End data with <CR><LF>.<CR><LF>"

    // Send email headers and body
    sprintf(message, "From: <%s>\r\n", email.sender_email);
    strcat(message, "To: <%s>\r\n");
    strcat(message, "Subject: %s\r\n");
    strcat(message, "%s\r\n.\r\n");
    send(sockfd, message, strlen(message), 0);

    // Reset message buffer
    bzero(message, MAX_BUFFER_SIZE);

    // Receive server response
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "250 OK"

    // Send QUIT command
    sprintf(message, "QUIT\r\n");
    send(sockfd, message, strlen(message), 0);

    // Receive server response
    bzero(message, MAX_BUFFER_SIZE);
    recv(sockfd, message, MAX_BUFFER_SIZE, 0);
    printf("%s", message); // expecting "221 Bye"

    // Close socket
    close(sockfd);
}