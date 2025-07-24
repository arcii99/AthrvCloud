//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 666

int main() {
    int sockfd, newsockfd, n;
    socklen_t len;
    char buffer[256];

    struct sockaddr_in server_addr, client_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("SETSOCKOPT");

    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    printf("Server started on port %d\n", PORT);
    len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr*) &client_addr, &len);

    if(newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    printf("Connection established with client %s\n", inet_ntoa(client_addr.sin_addr));

    while(1) {
        bzero(buffer,256);
        n = read(newsockfd, buffer, 255);

        if(n < 0) {
            perror("ERROR reading from socket");
            close(sockfd);
            exit(1);
        }
        printf("Client %s: %s\n", inet_ntoa(client_addr.sin_addr), buffer);
        
        printf("Your response: ");
        bzero(buffer,256);
        fgets(buffer, 255, stdin);
        n = write(newsockfd, buffer, strlen(buffer));

        if(n < 0) {
            perror("ERROR writing to socket");
            close(sockfd);
            exit(1);
        }
    }
    close(sockfd);
    return 0;
}