//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int receiveResponse(int sockfd, char *response);
int sendMessage(int sockfd, char *message);

int main(int argc , char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char response[MAXSIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Could not create socket");
        exit(1);
    }
     
    // Set server address and port number
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110); // POP3 port number
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Could not connect to the server");
        exit(1);
    }
     
    // Receive server welcome message
    receiveResponse(sockfd, response);
    printf("%s", response);
    
    // Send user credentials
    sendMessage(sockfd, "USER user@example.com\r\n");
    receiveResponse(sockfd, response);
    printf("%s", response);
    
    sendMessage(sockfd, "PASS mypassword123\r\n");
    receiveResponse(sockfd, response);
    printf("%s", response);
    
    // Request number of messages in the inbox
    sendMessage(sockfd, "STAT\r\n");
    receiveResponse(sockfd, response);
    printf("%s", response);
    
    // Quit the session 
    sendMessage(sockfd, "QUIT\r\n");

    close(sockfd);
    return 0;
}

int receiveResponse(int sockfd, char *response)
{
    memset(response, 0, MAXSIZE);
    if (recv(sockfd, response, MAXSIZE, 0) < 0) {
        printf("Could not receive response from the server");
        exit(1);
    }
    return 0;
}

int sendMessage(int sockfd, char *message)
{
    if (send(sockfd, message, strlen(message), 0) < 0) {
        printf("Could not send message to the server");
        exit(1);
    }
    return 0;
}