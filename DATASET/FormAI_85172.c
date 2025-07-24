//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

#define MAXLINE 4096

int main(int argc, char **argv) 
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) 
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, 10) == -1) 
    {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
    
    printf("HTTP proxy server started on port: %d\n", servaddr.sin_port);

    while (1) 
    {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1) 
        {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }
        
        recv(connfd, buff, MAXLINE, 0);
        sscanf(buff, "%s %s %s", method, uri, version);
        printf("%s %s %s\n", method, uri, version);

        if (strncmp(uri, "http://", 7) != 0) 
        {
            printf("URI must start with http://\n");
            exit(EXIT_FAILURE);
        }

        char *host = strstr(uri, "//") + 2;
        char *port = strstr(host, ":");

        if (port != NULL) 
        {
            *port++ = '\0';
        } 
        else 
        {
            port = "80";
        }

        struct hostent *he;
        struct in_addr **addr_list;

        if ((he = gethostbyname(host)) == NULL) 
        {
            herror("Error resolving host");
            exit(EXIT_FAILURE);
        }

        addr_list = (struct in_addr **)he->h_addr_list;

        for (int i = 0; addr_list[i] != NULL; i++) 
        {
            printf("%s\n", inet_ntoa(*addr_list[i]));
        }

        struct sockaddr_in serv_addr;
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(atoi(port));
        serv_addr.sin_addr = *((struct in_addr *)he->h_addr);
        memset(serv_addr.sin_zero, '\0', sizeof serv_addr.sin_zero);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) 
        {
            perror("Error connecting to server");
            exit(EXIT_FAILURE);
        }

        send(sockfd, buff, strlen(buff), 0);

        int n;
        while ((n = recv(sockfd, buff, MAXLINE, 0)) > 0) 
        {
            buff[n] = '\0';
            printf("%s", buff);
            send(connfd, buff, n, 0);
        }

        close(sockfd);
        close(connfd);
    }

    return EXIT_SUCCESS;
}