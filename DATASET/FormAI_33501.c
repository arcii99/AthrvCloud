//FormAI DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <unistd.h> 

int main() 
{ 
    int sockfd, newsockfd; 
    char buffer[1024]; 
    struct sockaddr_in serv_addr, cli_addr; 
    int n; 
    socklen_t clilen; 

    // Creating a socket 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) 
    { 
        perror("Error opening socket"); 
        exit(1); 
    } 

    // Setting up the server address 
    bzero((char *) &serv_addr, sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons(8080); 

    // Binding the socket to the server address 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    { 
        perror("Error on binding"); 
        exit(1); 
    } 

    // Listening for incoming connections 
    listen(sockfd, 5); 
    clilen = sizeof(cli_addr); 

    // Accepting an incoming connection 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); 
    if (newsockfd < 0) 
    { 
        perror("Error on accept"); 
        exit(1); 
    } 

    // Reading and printing the incoming data 
    bzero(buffer, 1024); 
    n = read(newsockfd, buffer, 1023); 
    if (n < 0) 
    { 
        perror("Error reading from socket"); 
        exit(1); 
    } 
    printf("%s\n", buffer); 

    // Sending a response back to the client 
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>\r\n"; 
    n = write(newsockfd, response, strlen(response)); 
    if (n < 0) 
    { 
        perror("Error writing to socket"); 
        exit(1); 
    } 

    // Closing the connection 
    close(newsockfd); 
    close(sockfd); 

    return 0; 
}