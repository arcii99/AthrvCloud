//FormAI DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
    char buff[1024]; 
  
    // Create a socket 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed...\n"); 
        return 0; 
    } 
    printf("Socket created successfully!\n"); 

    // Assign IP and port 
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(8080); 
  
    // Connect the client socket to server socket 
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Connection with the server failed...\n"); 
        return 0; 
    } 
    printf("Connected to the server successfully!\n"); 

    // Receive message from the server 
    bzero(buff, sizeof(buff)); 
    read(sockfd, buff, sizeof(buff)); 
    printf("Message from server: %s\n", buff); 

    // Send message to the server 
    bzero(buff, sizeof(buff)); 
    printf("Enter a message to send to the server: "); 
    fgets(buff, sizeof(buff), stdin); 
    write(sockfd, buff, sizeof(buff)); 

    // Close the socket 
    close(sockfd); 
}