//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define MAX 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, connfd, n, len;
    char buffer[MAX];
    struct sockaddr_in servaddr, cli;

    if(argc<2)
    {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
        error("Socket Creation Failed!");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(8080);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
        error("Could not connect to the Server!");

    printf("\n Connected to the Server !!! \n");
    printf("\n Initiating the Topology Mapping... \n");

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "GET / HTTP/1.1\r\n\r\n");

    if(write(sockfd, buffer, sizeof(buffer)) != 0)
        error("Could not write to Server!");

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if(n < 0)
        error("Could not read from Server!");

    printf("\n The Topology Map for the network: %s is as follows:\n", argv[1]);
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}