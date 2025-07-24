//FormAI DATASET v1.0 Category: Socket programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT     8080
#define MAXLINE  1024

int main(int argc, char *argv[]) 
{ 
    int sockfd; 
    struct sockaddr_in servaddr; 

    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    memset(&servaddr, 0, sizeof(servaddr)); 
    
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr)<=0) { 
        perror("Invalid address/ Address not supported"); 
        exit(EXIT_FAILURE); 
    } 

    // Connecting to server 
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) { 
        perror("connection failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    char buf[MAXLINE];
    int n;

    // Receiving message from server
    while ((n = read(sockfd, buf, MAXLINE)) > 0) {
        buf[n] = '\0';
        printf("Received message from server: %s", buf);

        // Sending message to server
        printf("Enter message: ");
        fgets(buf, MAXLINE, stdin);
        write(sockfd, buf, strlen(buf)+1);
    }

    if (n < 0) {
        perror("read error");
        exit(EXIT_FAILURE);
    }

    close(sockfd); 
    return 0; 
}