//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define HTTP_PORT 80 // the standard http port

int main (int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Please enter a URL to fetch!\n");
        return 1;
    }

    char *url = argv[1];
    char request[512];

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // open the tcp socket
    if (sockfd < 0) 
    {
        printf("ERROR opening socket\n");
        return 1;
    }

    server = gethostbyname(url); // get the ip address of the server
    if (server == NULL) 
    {
        printf("ERROR, no such host\n");
        return 1;
    }

    portno = HTTP_PORT; // connect to the http port
    memset(&serv_addr,0,sizeof(serv_addr)); // zero out the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    {
        printf("ERROR connecting\n");
        return 1;
    }

    snprintf(request,sizeof(request),"GET / HTTP/1.0\r\n"
             "User-Agent: Wget/1.9.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",url);

    printf("Sending request:\n%s\n",request);

    if (write(sockfd,request,strlen(request)) < 0) // write the http request to the socket
    {
        printf("ERROR writing to socket\n");
        return 1;
    }

    printf("Response:\n");

    char buffer[1024];
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) // read the response from the server
    {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    printf("\n");

    close(sockfd); // close the socket

    return 0;
}