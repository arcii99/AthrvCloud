//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 25 // SMTP port number
#define MAXLEN 1024 // Maximum message length

int main() {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[MAXLEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Creating a socket
    
    if(sockfd < 0) {
        perror("Error in creating socket: ");
        exit(1);
    }

    memset(&server_addr, '\0', sizeof(server_addr)); // Clearing the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)); // Connecting to the server
    
    if(ret < 0) {
        perror("Error in connecting to server: ");
        exit(1);
    }

    printf("Connected to the server!\n");

    strcpy(buffer, "EHLO medievalcastle.com\r\n"); // Sending the HELO command
    ret = send(sockfd, buffer, strlen(buffer), 0);

    if(ret < 0) {
        perror("Error in sending data: ");
        exit(1);
    }

    printf("Sent HELO command.\n");

    recv(sockfd, buffer, MAXLEN, 0); // Receiving the response from the server
    printf("Server response: %s\n", buffer);

    strcpy(buffer, "MAIL FROM: prince@medievalcastle.com\r\n"); // Sending the MAIL command
    ret = send(sockfd, buffer, strlen(buffer), 0);

    if(ret < 0) {
        perror("Error in sending data: ");
        exit(1);
    }

    printf("Sent MAIL FROM command.\n");

    recv(sockfd, buffer, MAXLEN, 0); // Receiving the response from the server
    printf("Server response: %s\n", buffer);

    strcpy(buffer, "RCPT TO: dragon@castle.com\r\n"); // Sending the RCPT command
    ret = send(sockfd, buffer, strlen(buffer), 0);

    if(ret < 0) {
        perror("Error in sending data: ");
        exit(1);
    }

    printf("Sent RCPT TO command.\n");

    recv(sockfd, buffer, MAXLEN, 0); // Receiving the response from the server
    printf("Server response: %s\n", buffer);

    strcpy(buffer, "DATA\r\n"); // Sending the DATA command
    ret = send(sockfd, buffer, strlen(buffer), 0);

    if(ret < 0) {
        perror("Error in sending data: ");
        exit(1);
    }

    printf("Sent DATA command.\n");

    recv(sockfd, buffer, MAXLEN, 0); // Receiving the response from the server
    printf("Server response: %s\n", buffer);

    strcpy(buffer, "Subject: Attack on the Castle!\r\n"); // Sending the email subject
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "The enemy has launched an attack on the castle walls! We must defend our land!\r\n"); // Sending the email message
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, ".\r\n"); // Indicating the end of the message
    ret = send(sockfd, buffer, strlen(buffer), 0);

    if(ret < 0) {
        perror("Error in sending data: ");
        exit(1);
    }

    printf("Sent email message.\n");

    recv(sockfd, buffer, MAXLEN, 0); // Receiving the response from the server
    printf("Server response: %s\n", buffer);

    strcpy(buffer, "QUIT\r\n"); // Sending the QUIT command
    ret = send(sockfd, buffer, strlen(buffer), 0);

    if(ret < 0) {
        perror("Error in sending data: ");
        exit(1);
    }

    printf("Sent QUIT command.\n");

    recv(sockfd, buffer, MAXLEN, 0); // Receiving the response from the server
    printf("Server response: %s\n", buffer);

    close(sockfd); // Closing the socket

    printf("Disconnected from the server.\n");

    return 0;
}