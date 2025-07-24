//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define MAX_REQUEST_LEN 8192
#define MAX_RESPONSE_LEN 8192
 
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define CLIENT_IP "127.0.0.1"
#define CLIENT_PORT 8080
 
int main()
{
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
 
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
 
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(CLIENT_PORT);
    client_addr.sin_addr.s_addr = inet_addr(CLIENT_IP);
 
    if((server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("Creating socket failed");
        exit(EXIT_FAILURE);
    }
 
    if((client_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("Creating socket failed");
        exit(EXIT_FAILURE);
    }
 
    if(bind(client_sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
    {
        printf("Binding failed");
        exit(EXIT_FAILURE);
    }
 
    if(connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection failed");
        exit(EXIT_FAILURE);
    }
 
    if(listen(client_sockfd, 5) < 0)
    {
        printf("Listen failed");
        exit(EXIT_FAILURE);
    }
 
    while(1)
    {
        int client_len = sizeof(client_addr);
        int client_connfd = accept(client_sockfd, (struct sockaddr *)&client_addr, &client_len);
 
        if(client_connfd < 0)
        {
            printf("Accept failed");
            exit(EXIT_FAILURE);
        }
 
        char request[MAX_REQUEST_LEN];
        char response[MAX_RESPONSE_LEN];
        ssize_t request_len, response_len;
 
        request_len = recv(client_connfd, request, MAX_REQUEST_LEN, 0);
 
        if(request_len < 0)
        {
            printf("Receiving failed");
            exit(EXIT_FAILURE);
        }
 
        printf("\nRequest:\n%s\n", request);
 
        if(send(server_sockfd, request, request_len, 0) < 0)
        {
            printf("Sending failed");
            exit(EXIT_FAILURE);
        }
 
        response_len = recv(server_sockfd, response, MAX_RESPONSE_LEN, 0);
 
        if(response_len < 0)
        {
            printf("Receiving failed");
            exit(EXIT_FAILURE);
        }
 
        printf("\nResponse:\n%s\n", response);
 
        if(send(client_connfd, response, response_len, 0) < 0)
        {
            printf("Sending failed");
            exit(EXIT_FAILURE);
        }
 
        close(client_connfd);
    }
 
    close(client_sockfd);
    close(server_sockfd);
 
    return 0;
}