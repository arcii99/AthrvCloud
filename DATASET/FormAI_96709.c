//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define HOSTNAME "imap.gmail.com"
#define PORT 993

void error_handler(char *message);
void receive_mail(int sockfd, char *username, char *password);

int main(int argc, char *argv[]) {
    if(argc < 3) {
        error_handler("Please provide an email address and password");
    }
    
    char *username = argv[1];
    char *password = argv[2];
    
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    
    memset(buffer, 0, sizeof(buffer));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_handler("Failed to create a socket");
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if(inet_pton(AF_INET, HOSTNAME, &serv_addr.sin_addr) <= 0) {
        error_handler("Invalid address/ Address not supported");
    }
    
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handler("Connection failed");
    }
    
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(bytes_received < 0) {
        error_handler("Failed to receive message from server");
    }
    
    printf("%s", buffer);
    
    // Login
    sprintf(buffer, "a001 LOGIN %s %s\n", username, password);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error_handler("Failed to send message to server");
    }
    
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Failed to receive message from server");
    }
    
    printf("%s", buffer);
    
    // Enter SELECTED state for INBOX
    sprintf(buffer, "a002 SELECT INBOX\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error_handler("Failed to send message to server");
    }
    
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Failed to receive message from server");
    }
    
    printf("%s", buffer);
    
    receive_mail(sockfd, username, password);
    
    return 0;
}

void receive_mail(int sockfd, char *username, char *password) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    memset(buffer, 0, sizeof(buffer));
    
    // List all messages
    sprintf(buffer, "a003 FETCH 1:* FLAGS BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error_handler("Failed to send message to server");
    }
    
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Failed to receive message from server");
    }
    
    printf("%s", buffer);
    
    // Logout and close connection
    sprintf(buffer, "a004 LOGOUT\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error_handler("Failed to send message to server");
    }
    
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error_handler("Failed to receive message from server");
    }
    
    printf("%s", buffer);
    
    close(sockfd);
}

void error_handler(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}