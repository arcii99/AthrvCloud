//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXBUF 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <smtp_server_ip> <from_address> <to_address>\n", argv[0]);
        exit(1);
    }
    
    char* smtp_server_ip = argv[1];
    char* from_address = argv[2];
    char* to_address = argv[3];
    
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[MAXBUF];
    char message[MAXBUF];
    memset(message, 0, MAXBUF);
    
    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    // Set up the server address
    portno = 25; /* SMTP port */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, smtp_server_ip, &serv_addr.sin_addr);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    // Read the server greeting message
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    // Send the HELO command
    sprintf(message, "HELO %s\r\n", smtp_server_ip);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    memset(buffer, 0, MAXBUF);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    // Send the MAIL command
    sprintf(message, "MAIL FROM: <%s>\r\n", from_address);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    memset(buffer, 0, MAXBUF);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    // Send the RCPT command
    sprintf(message, "RCPT TO: <%s>\r\n", to_address);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    memset(buffer, 0, MAXBUF);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    // Send the DATA command
    if (send(sockfd, "DATA\r\n", 6, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    memset(buffer, 0, MAXBUF);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    // Send the message body
    sprintf(message, "From: <%s>\r\n"
                     "To: <%s>\r\n"
                     "Subject: Test Email\r\n\r\n"
                     "Hello, this is a test email from the SMTP client.\r\n", from_address, to_address);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    
    // Send the end-of-message command
    if (send(sockfd, "\r\n.\r\n", 5, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    memset(buffer, 0, MAXBUF);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    memset(buffer, 0, MAXBUF);
    if (recv(sockfd, buffer, MAXBUF, 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);
    
    close(sockfd);
    return 0;
}