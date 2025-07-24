//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: satisfied
//A simple server-client communication program using TCP/IP sockets in C language.

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080

int main(){

    int sockfd, newsockfd, ret;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;

    /*opening socket*/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
        printf("Could not create socket\n");
        exit(1);
    }
    printf("Socket created successfully\n");

    /*populating server address structure*/
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    /*binding socket*/
    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret<0){
        printf("Could not bind to the address\n");
        exit(1);
    }
    printf("Bind successful\n");

    /*Listening for incoming connections*/
    if(listen(sockfd, 10) == 0){
        printf("Listening...\n");
    } else{
        printf("Error in listening\n");
        exit(1);
    }

    /*Accepting incoming connections*/
    addr_size = sizeof(clientAddr);
    newsockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &addr_size);
    if(newsockfd<0){
        printf("Error in accepting connection\n");
        exit(1);
    }
    printf("Connection accepted from client : %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    /*Communication*/
    char buffer[1024];
    pid_t childpid;
    int n;

    if((childpid = fork()) == 0){
        while(1){
            memset(buffer, '\0', 1024);
            n = read(newsockfd, buffer, 1024);
            if(n<0){
                printf("Error in reading from socket\n");
                exit(1);
            }
            printf("Client : %s\n", buffer);
            if(strncmp(buffer, "bye", 3) == 0){
                printf("Disconnecting from client : %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
                close(newsockfd);
                exit(0);
            }
        } 
    } else{
        while(1){
            memset(buffer, '\0', 1024);
            fgets(buffer, 1024, stdin);
            if(strncmp(buffer, "bye", 3) == 0){
                printf("Disconnecting\n");
                close(newsockfd);
                exit(0);
            }
            n = write(newsockfd, buffer, strlen(buffer)+1);
            if(n<0){
                printf("Error in writing to socket\n");
                exit(1);
            }
        }
    }
    return 0;
}