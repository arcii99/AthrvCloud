//FormAI DATASET v1.0 Category: Socket programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n, pid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5000;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    printf("Listening on port: %d\n", portno);

    while (1) 
    {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) 
        {
            perror("ERROR on accept");
            exit(1);
        }

        pid = fork();

        if (pid < 0) 
        {
            perror("ERROR on fork");
            exit(1);
        }

        if (pid == 0)  
        {
            close(sockfd);
            bzero(buffer,256);
            n = read(newsockfd,buffer,255);
            
            if (n < 0) 
            {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("Received message: %s\n",buffer);

            n = write(newsockfd,"I received your message",23);

            if (n < 0) 
            {
                perror("ERROR writing to socket");
                exit(1);
            }
            exit(0);
        }
        else 
        {
            close(newsockfd);
        }
    } 

    return 0;
}