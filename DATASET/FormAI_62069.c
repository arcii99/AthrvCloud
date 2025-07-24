//FormAI DATASET v1.0 Category: Simple Web Server ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define PORT 8080

void serve(int sockfd, struct sockaddr_in cli_addr, char buffer[])
{
    int n;
    char filename[50], ch;
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    sscanf(buffer,"%*s %s",filename);
    int fd=open(filename, O_RDONLY);
    if(fd<0)
    {
        write(sockfd,"HTTP/1.0 404 Not Found\n",23);
        write(sockfd,"Content-Type: text/html\n\n",25);
        write(sockfd,"<html><body><H1>File Not found</H1></body></html>\n",50);
    } else {
        write(sockfd,"HTTP/1.0 200 OK\n",15);
        write(sockfd,"Content-Type: text/html\n\n",25);
        while(read(fd,&ch,1)){
            write(sockfd,&ch,1);
        }
    }
    close(sockfd);
}

int main(int argc, char const *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n, pid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    for (;;)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd,
                           (struct sockaddr *)&cli_addr,
                           &clilen);
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
            serve(newsockfd, cli_addr, buffer);
            exit(0);
        }
        else
        {
            close(newsockfd);
        }
    }
    close(sockfd);
    return 0;
}