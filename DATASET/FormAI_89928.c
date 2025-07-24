//FormAI DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
    int sockfd, newsockfd, portno, clilen;

    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket

    // initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = 9000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind socket to server address
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // accept connection from client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    // read client message
    memset(buffer, 0, 256);
    read(newsockfd, buffer, 255);

    // print client message
    printf("Client: %s\n", buffer);

    // send response to client
    char response[] = "Hello from server!";
    write(newsockfd, response, strlen(response));

    // close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}