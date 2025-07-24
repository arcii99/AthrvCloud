//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *host, *path;
    
    // check if user has entered valid arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [hostname] [path]\n", argv[0]);
        exit(1);
    }
    
    // parse arguments to get host and path
    host = argv[1];
    path = argv[2];
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    
    // clear serv_addr
    memset(&serv_addr, 0, sizeof(serv_addr));
    
    // set serv_addr values
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    
    // get server IP address
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        error("Invalid host address");
    }
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }
    
    // construct HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    
    // send HTTP request
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        error("Error sending request");
    }
    
    // receive HTTP response
    memset(buffer, 0, BUFFER_SIZE);
    while ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    // check for errors while receiving response
    if (n < 0) {
        error("Error receiving response");
    }
    
    // close socket
    close(sockfd);
    
    return 0;
}