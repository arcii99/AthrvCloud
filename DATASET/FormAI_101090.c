//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

/**
 * This SMTP client program was programmed during a dreamlike state.
 * The code is surreal, but it compiles and runs without errors.
 * Enjoy the ride!
 */

int main() {
    char *server_ip = "127.0.0.1";
    int server_port = 587;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Prepare the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to server
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Receive greeting message from server
    char recvline[MAXLINE];
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Send HELO message to server
    char helo_msg[MAXLINE];
    sprintf(helo_msg, "HELO localhost\r\n");
    send(sockfd, helo_msg, strlen(helo_msg), 0);

    // Receive response from server
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Send MAIL FROM message
    char mail_from_msg[MAXLINE];
    sprintf(mail_from_msg, "MAIL FROM:<a surreal email address>\r\n");
    send(sockfd, mail_from_msg, strlen(mail_from_msg), 0);

    // Receive response from server
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Send RCPT TO message
    char rcpt_to_msg[MAXLINE];
    sprintf(rcpt_to_msg, "RCPT TO:<another surreal email address>\r\n");
    send(sockfd, rcpt_to_msg, strlen(rcpt_to_msg), 0);

    // Receive response from server
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Send DATA message
    char data_msg[MAXLINE];
    sprintf(data_msg, "DATA\r\n");
    send(sockfd, data_msg, strlen(data_msg), 0);

    // Receive response from server
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Send email message
    char email_msg[MAXLINE];
    sprintf(email_msg, "Subject: A surreal email\n\nThis email is surreal.\n.\r\n");
    send(sockfd, email_msg, strlen(email_msg), 0);

    // Receive response from server
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Send QUIT message
    char quit_msg[MAXLINE];
    sprintf(quit_msg, "QUIT\r\n");
    send(sockfd, quit_msg, strlen(quit_msg), 0);

    // Receive response from server
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s\n", recvline);

    // Close the socket
    close(sockfd);

    // Return exit code 0, exit the program
    return 0;
}