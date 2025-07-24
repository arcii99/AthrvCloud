//FormAI DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(){
    int sockfd, newsockfd;
    socklen_t len;
    struct sockaddr_in server, client;
    char buffer[BUFFER_SIZE];
    int n, err;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        perror("socket");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    err = bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    if(err < 0){
        perror("bind");
        return -1;
    }

    if(listen(sockfd, MAX_CLIENTS) < 0){
        perror("listen");
        return -1;
    }

    printf("Server started on port 8080\n");

    while(1){
        len = sizeof(client);
        newsockfd = accept(sockfd, (struct sockaddr*)&client, &len);

        if(newsockfd < 0){
            perror("accept");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        memset(buffer, 0, BUFFER_SIZE);
        while((n = read(newsockfd, buffer, BUFFER_SIZE)) > 0){
            printf("Client %s:%d sent message: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buffer);
            write(newsockfd, buffer, strlen(buffer));
            memset(buffer, 0, BUFFER_SIZE);
        }
        if(n < 0){
            perror("read");
            return -1;
        }
        close(newsockfd);

    }

    close(sockfd);

    return 0;
}