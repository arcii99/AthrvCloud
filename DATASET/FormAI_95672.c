//FormAI DATASET v1.0 Category: Networking ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main()
{
    int sockfd, newsockfd, n;
    socklen_t clilen;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0)
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if(newsockfd<0)
    {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        bzero(buffer, BUF_SIZE);

        n = read(newsockfd, buffer, BUF_SIZE);
        if(n<0)
        {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }
        printf("Client: %s", buffer);

        bzero(buffer, BUF_SIZE);

        printf("Enter your message: ");
        fgets(buffer, BUF_SIZE, stdin);

        n = write(newsockfd, buffer, BUF_SIZE);
        if(n<0)
        {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }

        if(!strncmp("exit", buffer, 4))
            break;
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}