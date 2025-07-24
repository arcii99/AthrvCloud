//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> // for sockets
#include <netinet/in.h> // for internet address structures
#include <arpa/inet.h> // for IP address conversion functions
#include <unistd.h> // for close() function

#define BUF_SIZE 4096

int main(int argc, char** argv) {
    // Check command line arguments
    if (argc != 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(1);
    }
    char* server_address = argv[1];
    char* username = argv[2];
    char* password = argv[3];
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }
    
    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110); // POP3 server port number
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }
    
    // receive server welcome message
    char buf[BUF_SIZE];
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("%s", buf);
    
    // Send username
    char command[BUF_SIZE];
    sprintf(command, "USER %s\r\n", username);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("%s", buf);
    
    // Send password
    sprintf(command, "PASS %s\r\n", password);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("%s", buf);
    
    // List messages
    if (send(sockfd, "LIST\r\n", 6, 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("%s", buf);
    
    // Retrieve first message
    if (send(sockfd, "RETR 1\r\n", 8, 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(1);
    }
    printf("%s", buf);
    
    // Quit session
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("send() failed");
        exit(1);
    }
    printf("Session terminated.\n");
    
    // Close socket
    close(sockfd);
    
    return 0;
}