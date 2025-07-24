//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[BUFF_SIZE];
    struct sockaddr_in serv_addr;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    // initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    
    // send message to server
    char* message = "Hello server!";
    int n = write(sockfd, message, strlen(message));
    if (n < 0) 
        error("ERROR writing to socket");
    
    // receive message from server
    memset(buffer, 0, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("Server response: %s\n", buffer);
    
    // close connection
    close(sockfd);
    return 0;
}