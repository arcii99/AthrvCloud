//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(){
    int sockfd, connfd, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("Error: Could not create server socket");
    }
    printf("Socket created successfully\n");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        error("Error: Could not bind to socket");
    }
    printf("Bind successful\n");
    if(listen(sockfd, 5) < 0){
        error("Error: Could not listen on socket");
    }
    printf("Listening for incoming connections...\n");
    while(1){
        connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);
        if(connfd < 0){
            error("Error: Could not accept incoming connection");
        }
        printf("Connection accepted\n");
        memset(buffer, 0, sizeof(buffer));
        n = read(connfd, buffer, sizeof(buffer)-1);
        if(n < 0){
            error("Error: Could not read from socket");
        }
        printf("Received message from client:\n%s\n", buffer);
        bzero(buffer, 256);
        char response[256] = "Message received!";
        n = write(connfd, response, strlen(response));
        if(n < 0){
            error("Error: Could not write to socket");
        }
        close(connfd);
    }
    close(sockfd);
    return 0;
}