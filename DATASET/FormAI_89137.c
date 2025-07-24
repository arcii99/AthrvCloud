//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "smtp.gmail.com"
#define PORT 587

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Error\n");
        return 1;
    }

    // Receive initial message from server
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", SERVER);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<sender@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<receiver@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send message contents
    sprintf(buffer, "From: sender@gmail.com\r\nTo: receiver@gmail.com\r\nSubject: Test Email\r\n\r\nThis is a test email from my C SMTP Client!\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}