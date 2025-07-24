//FormAI DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define BUFSIZE 1024

int main(){
    //initialize variables
    int sockfd, newsockfd, clilen, n;
    char buffer[BUFSIZE];
    struct sockaddr_in server_addr, client_addr;

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error opening socket");
        exit(1);
    }

    //set server address
    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    //bind socket to address
    if(bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0){
        perror("Error binding socket");
        exit(1);
    }

    //listen for incoming connections
    listen(sockfd, 5);

    //accept connection from client
    clilen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr*) &client_addr, &clilen);
    if(newsockfd < 0){
        perror("Error accepting connection");
        exit(1);
    }

    //read HTTP request
    bzero(buffer, BUFSIZE);
    n = read(newsockfd, buffer, BUFSIZE-1);
    if(n < 0){
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    //parse HTTP request
    char* http_method = strtok(buffer, " ");
    char* http_path = strtok(NULL, " ");
    char* http_version = strtok(NULL, "\r\n");

    //check if HTTP request is GET
    if(strcmp(http_method, "GET") != 0){
        perror("HTTP method not implemented");
        exit(1);
    }

    //open file requested
    char filepath[BUFSIZE];
    sprintf(filepath, ".%s", http_path);
    int fd = open(filepath, O_RDONLY);
    if(fd < 0){
        perror("Error opening file");
        send(newsockfd, "HTTP/1.1 404 Not Found\r\n", 22, 0);
        exit(1);
    }

    //send HTTP response header
    char response_header[BUFSIZE];
    sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    send(newsockfd, response_header, strlen(response_header), 0);

    //send file contents
    bzero(buffer, BUFSIZE);
    while((n = read(fd, buffer, BUFSIZE)) > 0){
        send(newsockfd, buffer, n, 0);
        bzero(buffer, BUFSIZE);
    }

    //close sockets and file
    close(newsockfd);
    close(sockfd);
    close(fd);

    return 0;
}