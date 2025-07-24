//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    printf("Socket creation successful!\n");

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("216.58.194.174");

    // connect to the server
    if(connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    {
        perror("connection to server failed!");
        exit(EXIT_FAILURE);
    }
    printf("Connection to server successful!\n");

    char *http_request = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";

    // send request to server
    if(send(sockfd, http_request, strlen(http_request), 0) < 0)
    {
        perror("Sending request to server failed!");
        exit(EXIT_FAILURE);
    }
    printf("Request sent to server successfully!\n");

    char server_response[10000];
    memset(server_response, 0, sizeof(server_response));

    // receive response from server
    if(recv(sockfd, server_response, sizeof(server_response), 0) < 0)
    {
        perror("Receiving response from server failed!");
        exit(EXIT_FAILURE);
    }
    printf("Response received from server successfully!\n");

    printf("%s", server_response);

    close(sockfd);

    return 0;
}