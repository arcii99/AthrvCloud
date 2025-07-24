//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        return 1;
    }

    // Setting server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to actual SMTP server IP address
    server_addr.sin_port = htons(25); // Set the port number

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Sending HELO command to server
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "HELO client\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send HELO command");
        return 1;
    }
    printf("Sent: %s", buffer);

    // Receiving response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Received: %s", buffer);

    // Sending MAIL FROM command to server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send MAIL FROM command");
        return 1;
    }
    printf("Sent: %s", buffer);

    // Receiving response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Received: %s", buffer);

    // Sending RCPT TO command to server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send RCPT TO command");
        return 1;
    }
    printf("Sent: %s", buffer);

    // Receiving response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Received: %s", buffer);

    // Sending DATA command to server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send DATA command");
        return 1;
    }
    printf("Sent: %s", buffer);

    // Receiving response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Received: %s", buffer);

    // Sending message body to server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "From: <sender@example.com>\r\nTo: <recipient@example.com>\r\nSubject: Hello\r\n\r\nHello, World!\r\n.\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message body");
        return 1;
    }
    printf("Sent: %s", buffer);

    // Receiving response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Received: %s", buffer);

    // Sending QUIT command to server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send QUIT command");
        return 1;
    }
    printf("Sent: %s", buffer);

    // Receiving response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Received: %s", buffer);

    // Closing socket
    close(sockfd);

    return 0;
}