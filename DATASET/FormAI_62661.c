//FormAI DATASET v1.0 Category: Networking ; Style: interoperable
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <netdb.h>  

#define PORT 8080  

int main()  
{  
    int sockfd;  
    struct sockaddr_in server_addr;  
    char buffer[1024];  

    // Creating socket file descriptor  
    sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (sockfd < 0)  
    {  
        perror("socket creation failed");  
        exit(EXIT_FAILURE);  
    }  

    // Setting up the server address
    memset(&server_addr, 0, sizeof(server_addr));  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(PORT);  
    server_addr.sin_addr.s_addr = INADDR_ANY;  

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)  
    {  
        perror("connect to server failed");  
        exit(EXIT_FAILURE);  
    }  

    while (1)  
    {  
        printf("Enter message to send: ");  
        fgets(buffer, 1024, stdin);  

        if (send(sockfd, buffer, strlen(buffer), 0) < 0)  
        {  
            perror("send failed");  
            exit(EXIT_FAILURE);  
        }  

        memset(buffer, 0, sizeof(buffer));  
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)  
        {  
            perror("recv failed");  
            exit(EXIT_FAILURE);  
        }  

        printf("Server sent: %s", buffer);  
    }  

    close(sockfd);  
    return 0;  
}