//FormAI DATASET v1.0 Category: Simple Web Server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    //Creating a Socket File Descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) error("Error opening socket");

    //Defining sockaddr_in struct
    struct sockaddr_in servAddr, clientAddr;
    memset(&servAddr, '\0', sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(8080);

    //Binding to the port
    if(bind(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
        error("Binding Failed");

    //Listening for Incoming Connections
    listen(sockfd, 5);

    while(1)
    {
        unsigned int clientLen = sizeof(clientAddr);
        //Establishing Connection with Client
        int newsockfd = accept(sockfd, (struct sockaddr *) &clientAddr, &clientLen);
        if(newsockfd < 0) error("Error in accepting connection");

        //Reading HTTP Request from the Client
        char httpRequest[1024];
        memset(httpRequest, '\0', sizeof(httpRequest));
        read(newsockfd, httpRequest, sizeof(httpRequest)-1);

        //Serving the Response
        char httpResponse[1024];
        memset(httpResponse, '\0', sizeof(httpResponse));
        sprintf(httpResponse, "HTTP/1.1 200 OK\r\n\r\nHello World!\n");
        write(newsockfd, httpResponse, strlen(httpResponse));

        //Closing the Connection
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}