//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main(){
    char server_address[50], from_address[50], to_address[50], subject[100], message[BUFFER_SIZE];
    printf("Welcome to the SMTP Client program!\n\n");
    printf("Please enter the server address: ");
    fgets(server_address, 50, stdin);
    server_address[strcspn(server_address, "\n")] = 0; //remove newline character
    
    struct sockaddr_in server_sockaddr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Error creating TCP socket.\n");
        exit(1);
    }
    
    memset(&server_sockaddr, 0, sizeof(server_sockaddr));
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(SERVER_PORT);
    if(inet_pton(AF_INET, server_address, &server_sockaddr.sin_addr) <= 0){
        printf("Invalid server IP address.\n");
        exit(1);
    }
    
    if(connect(sockfd, (struct sockaddr*)&server_sockaddr, sizeof(server_sockaddr)) < 0){
        printf("Failed to connect to server.\n");
        exit(1);
    }
    
    char resp[BUFFER_SIZE];
    recv(sockfd, resp, BUFFER_SIZE, 0);
    if(strncmp(resp, "220", 3) != 0){
        printf("Unexpected response from server: %s\n", resp);
        exit(1);
    }
    
    printf("Server connected. Please enter sender email address: ");
    fgets(from_address, 50, stdin);
    from_address[strcspn(from_address, "\n")] = 0;
    sprintf(message, "MAIL FROM:<%s>\r\n", from_address);
    send(sockfd, message, strlen(message), 0);
    
    memset(resp, 0, sizeof(resp));
    recv(sockfd, resp, BUFFER_SIZE, 0);
    if(strncmp(resp, "250", 3) != 0){
        printf("Unexpected response from server: %s\n", resp);
        exit(1);
    }
    
    printf("Sender email address accepted. Please enter recipient email address: ");
    fgets(to_address, 50, stdin);
    to_address[strcspn(to_address, "\n")] = 0;
    sprintf(message, "RCPT TO:<%s>\r\n", to_address);
    send(sockfd, message, strlen(message), 0);
    
    memset(resp, 0, sizeof(resp));
    recv(sockfd, resp, BUFFER_SIZE, 0);
    if(strncmp(resp, "250", 3) != 0){
        printf("Unexpected response from server: %s\n", resp);
        exit(1);
    }
    
    printf("Recipient email address accepted. Please enter email subject: ");
    fgets(subject, 100, stdin);
    subject[strcspn(subject, "\n")] = 0;
    
    printf("Please enter your message: ");
    fgets(message, BUFFER_SIZE, stdin);
    int len = strlen(message);
    if(message[len-1] == '\n'){
        message[len-1] = '\0';
    }
    
    sprintf(message, "DATA\r\nFrom:<%s>\r\nTo:<%s>\r\nSubject:%s\r\n\r\n%s\r\n.\r\n", from_address, to_address, subject, message);
    send(sockfd, message, strlen(message), 0);
    
    memset(resp, 0, sizeof(resp));
    recv(sockfd, resp, BUFFER_SIZE, 0);
    if(strncmp(resp, "250", 3) != 0){
        printf("Unexpected response from server: %s\n", resp);
        exit(1);
    }
    
    printf("Email sent successfully. Closing connection.\n");
    sprintf(message, "QUIT\r\n");
    send(sockfd, message, strlen(message), 0);
    
    memset(resp, 0, sizeof(resp));
    recv(sockfd, resp, BUFFER_SIZE, 0);
    if(strncmp(resp, "221", 3) != 0){
        printf("Unexpected response from server: %s\n", resp);
        exit(1);
    }
    
    close(sockfd);
    return 0;
}