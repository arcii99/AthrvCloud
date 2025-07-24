//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
/* 

Title: The Simple HTTP Proxy
Author: Claude Shannon
Date: 1951

*/

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

int main(void)
{
    int sockfd, newsockfd, n;
    char buffer[4096];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        perror("ERROR on accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        n = read(newsockfd, buffer, sizeof(buffer) - 1);

        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        if (n == 0)
        {
            printf("Connection closed by peer\n");
            break;
        }

        printf("Received %d bytes from client:\n%s\n", n, buffer);

        // Replace "www.example.com" with the website you want to proxy
        char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
        int request_len = strlen(request);

        // Connect to the remote server
        struct hostent *he = gethostbyname("www.example.com");
        struct sockaddr_in remote_addr;
        int remote_fd;

        remote_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (remote_fd < 0)
        {
            perror("ERROR opening socket");
            exit(EXIT_FAILURE);
        }

        memset((char *)&remote_addr, 0, sizeof(remote_addr));

        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr = *((struct in_addr *)he->h_addr);
        remote_addr.sin_port = htons(80);

        if (connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0)
        {
            perror("ERROR connecting");
            exit(EXIT_FAILURE);
        }

        // Send the request to the remote server
        n = write(remote_fd, request, request_len);

        if (n < 0)
        {
            perror("ERROR writing to socket");
            exit(EXIT_FAILURE);
        }

        // Read the response from the remote server
        memset(buffer, 0, sizeof(buffer));
        n = read(remote_fd, buffer, sizeof(buffer) - 1);

        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        printf("Received %d bytes from server:\n%s\n", n, buffer);

        // Send the response back to the client
        n = write(newsockfd, buffer, n);

        if (n < 0)
        {
            perror("ERROR writing to socket");
            exit(EXIT_FAILURE);
        }

        printf("Sent %d bytes to client\n", n);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}