//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char send_data[1024], recv_data[4096];
    int port = 80;

    host = gethostbyname("www.example.com");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket Error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_addr.sin_zero),8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Connect Error");
        exit(1);
    }

    sprintf(send_data, "GET / HTTP/1.1\r\n");
    sprintf(send_data, "%sHost: www.example.com\r\n\r\n", send_data);
    send(sockfd, send_data, strlen(send_data), 0);

    printf("Request sent:\n%s", send_data);

    int bytes_received = recv(sockfd, recv_data, 4096, 0);
    recv_data[bytes_received] = '\0';

    printf("Response received:\n%s", recv_data);

    close(sockfd);
    return 0;
}