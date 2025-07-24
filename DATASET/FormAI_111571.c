//FormAI DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <netinet/in.h> 

#define PROTOCOL 0 
#define BUF_SIZE 100 
#define SERV_PORT 8080 

void handle_request(int sockfd, char *buffer)
{
    char *response = "<h1>Hello, World!</h1>";
    char *header = "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: text/html\r\n\r\n";
    char res_buf[BUF_SIZE+strlen(header)];
    sprintf(res_buf, header, strlen(response));
    strcat(res_buf, response);
    write(sockfd, res_buf, strlen(res_buf));
}

int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, PROTOCOL)) == -1) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Configure server address and port
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(SERV_PORT); 

    // Bind the socket with the server address 
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listen for incoming connections 
    if (listen(sockfd, 5) == -1) { 
        perror("listen failed"); 
        exit(EXIT_FAILURE); 
    } 

    int len = sizeof(cli); 

    while(1) { 
        char buffer[BUF_SIZE];

        // Accept a connection
        connfd = accept(sockfd, (struct sockaddr *)&cli, &len); 
        if (connfd < 0) { 
            perror("accept failed"); 
            exit(EXIT_FAILURE); 
        } 

        // Read the request
        read(connfd, buffer, BUF_SIZE); 
        printf("%s", buffer);

        // Handle the request
        handle_request(connfd, buffer);

        // Close the connection
        close(connfd); 
    } 

    // Close the socket
    close(sockfd); 

    return 0; 
}