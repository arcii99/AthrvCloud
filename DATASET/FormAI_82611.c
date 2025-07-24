//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 25

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    
    // Receive greeting message from server
    char greeting[1024];
    if (recv(sockfd, greeting, sizeof(greeting), 0) < 0) {
        perror("Failed to receive greeting message");
        exit(EXIT_FAILURE);
    }
    printf("%s", greeting);
    
    // Send HELO command to server
    char helo_cmd[1024];
    sprintf(helo_cmd, "HELO %s\r\n", SERVER_ADDR);
    if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) < 0) {
        perror("Failed to send HELO command");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from server
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    
    // Send MAIL FROM command to server
    char from_cmd[1024];
    sprintf(from_cmd, "MAIL FROM:<sender@domain.com>\r\n");
    if (send(sockfd, from_cmd, strlen(from_cmd), 0) < 0) {
        perror("Failed to send MAIL FROM command");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from server
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    
    // Send RCPT TO command to server
    char rcpt_cmd[1024];
    sprintf(rcpt_cmd, "RCPT TO:<recipient@domain.com>\r\n");
    if (send(sockfd, rcpt_cmd, strlen(rcpt_cmd), 0) < 0) {
        perror("Failed to send RCPT TO command");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from server
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    
    // Send DATA command to server
    char data_cmd[1024];
    sprintf(data_cmd, "DATA\r\n");
    if (send(sockfd, data_cmd, strlen(data_cmd), 0) < 0) {
        perror("Failed to send DATA command");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from server
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    
    // Send email message to server
    char message[] = "Subject: Test email\nThis is a test email.\n.\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Failed to send email message");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from server
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    
    // Send QUIT command to server
    char quit_cmd[1024];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("Failed to send QUIT command");
        exit(EXIT_FAILURE);
    }
    
    // Receive response from server
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
    
    // Close socket
    close(sockfd);
    
    return 0;
}