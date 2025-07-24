//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
 
#define DEFAULT_PORT 25
#define MAX_BUFFER_SIZE 1024
 
int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE];
 
    // Step 1: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }
 
    // Step 2: Connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        perror("Error connecting to server.");
        exit(EXIT_FAILURE);
    }
 
    printf("Connected to server.\n");
 
    // Step 3: Receive banner message from server
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving banner message.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 4: Send HELO message
    sprintf(message, "HELO smtp.example.com\r\n");
    if(send(sockfd, message, strlen(message), 0) == -1){
        perror("Error sending HELO message.");
        exit(EXIT_FAILURE);
    }
 
    // Step 5: Receive response to HELO message
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving response to HELO message.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 6: Send MAIL FROM command
    sprintf(message, "MAIL FROM:<sender@example.com>\r\n");
    if(send(sockfd, message, strlen(message), 0) == -1){
        perror("Error sending MAIL FROM command.");
        exit(EXIT_FAILURE);
    }
 
    // Step 7: Receive response to MAIL FROM command
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving response to MAIL FROM command.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 8: Send RCPT TO command
    sprintf(message, "RCPT TO:<recipient@example.com>\r\n");
    if(send(sockfd, message, strlen(message), 0) == -1){
        perror("Error sending RCPT TO command.");
        exit(EXIT_FAILURE);
    }
 
    // Step 9: Receive response to RCPT TO command
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving response to RCPT TO command.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 10: Send DATA command
    sprintf(message, "DATA\r\n");
    if(send(sockfd, message, strlen(message), 0) == -1){
        perror("Error sending DATA command.");
        exit(EXIT_FAILURE);
    }
 
    // Step 11: Receive response to DATA command
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving response to DATA command.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 12: Send email message
    sprintf(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    if(send(sockfd, message, strlen(message), 0) == -1){
        perror("Error sending email message.");
        exit(EXIT_FAILURE);
    }
 
    // Step 13: Receive response to email message
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving response to email message.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 14: Send QUIT command
    sprintf(message, "QUIT\r\n");
    if(send(sockfd, message, strlen(message), 0) == -1){
        perror("Error sending QUIT command.");
        exit(EXIT_FAILURE);
    }
 
    // Step 15: Receive response to QUIT command
    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1){
        perror("Error receiving response to QUIT command.");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
 
    // Step 16: Close socket
    close(sockfd);
 
    return 0;
}