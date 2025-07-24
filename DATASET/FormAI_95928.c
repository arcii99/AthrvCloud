//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <smtp-server-ip> <from-email-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket for TCP connection with the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);  // SMTP port
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the greeting message from the server
    char buffer[BUFFER_SIZE];
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send the EHLO command to the server
    char ehlo_cmd[BUFFER_SIZE];
    sprintf(ehlo_cmd, "EHLO %s\r\n", argv[2]);
    if (send(sockfd, ehlo_cmd, strlen(ehlo_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send the MAIL FROM command to the server
    char mail_from_cmd[BUFFER_SIZE];
    sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", argv[2]);
    if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send the RCPT TO command to the server
    char rcpt_to_cmd[BUFFER_SIZE];
    printf("Enter the recipient email address: ");
    fflush(stdout);
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = '\0';  // Remove the newline character
    sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", buffer);
    if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send the DATA command to the server
    char data_cmd[BUFFER_SIZE];
    sprintf(data_cmd, "DATA\r\n");
    if (send(sockfd, data_cmd, strlen(data_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send the message body to the server
    printf("Enter the message body (end with a single period on a line by itself):\n");
    fflush(stdout);
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        if (strcmp(buffer, ".\n") == 0) {  // End of message body
            break;
        }
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    // Send the QUIT command to the server
    char quit_cmd[BUFFER_SIZE];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}