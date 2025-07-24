//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char** argv){

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error in creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr, client_addr;
    int portno = 9999;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Error in binding");
        exit(1);
    }

    listen(sockfd, 5);

    socklen_t client_len = sizeof(client_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if(newsockfd < 0){
        perror("Error in accepting");
        exit(1);
    }

    printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    char buffer[500];
    memset(buffer, 0, sizeof(buffer));

    int n = read(newsockfd, buffer, sizeof(buffer));
    if(n < 0){
        perror("Error in reading from socket");
        exit(1);
    }

    printf("Message Received: %s\n", buffer);

    char* str = "Message Received\n";
    n = write(newsockfd, str, strlen(str));
    if(n < 0){
        perror("Error in writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}