//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 1024
#define PORT 25

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX];

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed");
        exit(0);
    }
    else
        printf("Socket created successfully\n");

    // Setting server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "localhost", &servaddr.sin_addr);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed");
        exit(0);
    }
    else
        printf("Connected to the server\n");

    // Reading the response from server
    bzero(buffer, MAX);
    read(sockfd, buffer, MAX);
    printf("Response from server: %s\n", buffer);

    // Sending the HELO command to server
    char helo[MAX] = "HELO client\r\n";
    write(sockfd, helo, strlen(helo) * sizeof(char));
    printf("HELO command sent to server: %s\n", helo);

    // Reading the response from server
    bzero(buffer, MAX);
    read(sockfd, buffer, MAX);
    printf("Response from server: %s\n", buffer);

    // Sending the MAIL FROM command to server
    char mailfrom[MAX] = "MAIL FROM: <your_email_address>\r\n";
    write(sockfd, mailfrom, strlen(mailfrom) * sizeof(char));
    printf("MAIL FROM command sent to server: %s\n", mailfrom);

    // Reading the response from server
    bzero(buffer, MAX);
    read(sockfd, buffer, MAX);
    printf("Response from server: %s\n", buffer);

    // Sending the RCPT TO command to server
    char rcptto[MAX] = "RCPT TO: <recipient_email_address>\r\n";
    write(sockfd, rcptto, strlen(rcptto) * sizeof(char));
    printf("RCPT TO command sent to server: %s\n", rcptto);

    // Reading the response from server
    bzero(buffer, MAX);
    read(sockfd, buffer, MAX);
    printf("Response from server: %s\n", buffer);

    // Sending the DATA command to server
    char data[MAX] = "DATA\r\n";
    write(sockfd, data, strlen(data) * sizeof(char));
    printf("DATA command sent to server: %s\n", data);

    // Reading the response from server
    bzero(buffer, MAX);
    read(sockfd, buffer, MAX);
    printf("Response from server: %s\n", buffer);

    // Sending the subject and body of message to server
    char subject[MAX] = "Subject: SMTP Client Example\r\n";
    char body[MAX] = "This is a test email sent from SMTP client.\r\n";
    write(sockfd, subject, strlen(subject) * sizeof(char));
    write(sockfd, body, strlen(body) * sizeof(char));

    // Sending the QUIT command to server
    char quit[MAX] = "QUIT\r\n";
    write(sockfd, quit, strlen(quit) * sizeof(char));
    printf("QUIT command sent to server: %s\n", quit);

    close(sockfd);
    return 0;
}