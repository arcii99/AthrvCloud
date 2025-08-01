//FormAI DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 
#define MAX 100 

int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cliaddr; 

    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 

    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    // Binding socket to server address 
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 

    // Listening to incoming connections 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cliaddr); 

    // Accepting incoming connections 
    connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 

    // Communication with client 
    char buff[MAX]; 
    int n; 
    bzero(buff, MAX); 
    read(connfd, buff, sizeof(buff)); 
    printf("From client: %s\t To client : ", buff); 
    bzero(buff, MAX); 
    n = 0; 
    while ((buff[n++] = getchar()) != '\n') 
        ; 
    write(connfd, buff, sizeof(buff)); 

    // Closing socket 
    close(sockfd); 
}