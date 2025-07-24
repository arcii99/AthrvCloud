//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define PORT 9000
#define BUFFER_SIZE 1024
 
int main(){
    int sockfd, newsockfd;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in servaddr, cliaddr;
    int len = sizeof(cliaddr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("Bind error");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    if(listen(sockfd, 5) < 0){
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t*)&len);
    if(newsockfd < 0){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    while(1){
        memset(buffer, 0, BUFFER_SIZE);
        int n;
        n = read(newsockfd, buffer, BUFFER_SIZE);
        if(n < 0){
            perror("Read error");
            exit(EXIT_FAILURE);
        }
        printf("Client message: %s\n", buffer);

        if(strcmp(buffer, "exit") == 0){
            printf("Server closing connection\n");
            break;
        }

        strcat(buffer, " - received");
        n = write(newsockfd, buffer, strlen(buffer));
        if(n < 0){
            perror("Write error");
            exit(EXIT_FAILURE);
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}