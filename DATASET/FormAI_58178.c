//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netdb.h> 

#define PORT 8080 

void error(char *msg) 
{ 
    perror(msg); 
    exit(0); 
} 

int main(int argc, char *argv[]) 
{ 
    int sockfd, newsockfd, n; 
    struct sockaddr_in proxy_addr, server_addr, client_addr; 
    char buffer[1024], ipstr[INET_ADDRSTRLEN]; 
    socklen_t clilen; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) 
        error("Error opening socket"); 

    bzero((char *) &proxy_addr, sizeof(proxy_addr)); 
    proxy_addr.sin_family = AF_INET; 
    proxy_addr.sin_addr.s_addr = INADDR_ANY; 
    proxy_addr.sin_port = htons(PORT); 

    if (bind(sockfd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) 
        error("Error on binding"); 

    listen(sockfd, 5); 
    clilen = sizeof(client_addr); 

    while (1) { 
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen); 
        if (newsockfd < 0) 
            error("Error on accept"); 

        inet_ntop(AF_INET, &(client_addr.sin_addr), ipstr, INET_ADDRSTRLEN); 

        printf("Connection from %s:%d\n",ipstr, ntohs(client_addr.sin_port)); 

        bzero(buffer, 1024); 
        n = read(newsockfd, buffer, 1023); 
        if (n < 0) 
            error("Error reading from socket"); 

        printf("Request from client:\n%s\n", buffer); 

        // get request hostname from request header
        char* token = strtok(buffer, " ");
        token = strtok(NULL, "/");
        char* hostname = strtok(NULL, "/");
        hostname = strtok(hostname, "\r");

        struct hostent *server = gethostbyname(hostname); 
        if (server == NULL) 
            error("Error getting host");

        printf("Proxy requests %s from %s:%d\n", buffer, hostname, ntohs(server_addr.sin_port)); 

        bzero((char *) &server_addr, sizeof(server_addr)); 
        server_addr.sin_family = AF_INET; 
        bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length); 
        server_addr.sin_port = htons(80); 

        // create a new socket to connect to server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) 
            error("Error opening socket"); 

        if (connect(server_sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) 
            error("Error connecting to server"); 

        // send request to server
        n = write(server_sockfd, buffer, strlen(buffer)); 
        if (n < 0) 
            error("Error writing to socket"); 

        bzero(buffer,1024); 

        // receive response from server
        n = read(server_sockfd,buffer,1023); 
        if (n < 0) 
            error("Error reading from socket"); 

        printf("Response from server:\n%s\n", buffer); 

        // send response to client
        n = write(newsockfd,buffer,strlen(buffer)); 
        if (n < 0) 
            error("Error writing to socket");

        close(server_sockfd);
        close(newsockfd); 
    } 

    close(sockfd); 
    return 0; 
}