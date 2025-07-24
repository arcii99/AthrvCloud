//FormAI DATASET v1.0 Category: Networking ; Style: calm
/*This is a program that demonstrates networking in C language
It creates a server that listens to incoming connections from a client
The server then sends a message to the client and waits for a response*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[255];
    struct sockaddr_in serv_addr, cli_addr;

    //Create a socket that uses the TCP protocol
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Failed to open socket!\n");
        exit(1);
    }

    //Clear the server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));

    //Set the port number and address family
    portno = 5000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    //Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error: Failed to bind socket to address!\n");
        exit(1);
    }

    //Listen for incoming connections from client
    listen(sockfd, 5);
    printf("Server started. Listening on port %d...\n", portno);

    //Accept incoming connections from client
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
        printf("Error: Failed to accept incoming connection!\n");
        exit(1);
    }

    //Send a message to the client
    strcpy(buffer, "Hello from server!\n");
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        printf("Error: Failed to send message to client!\n");
        exit(1);
    }

    //Wait for a response from the client
    bzero(buffer, 255);
    n = read(newsockfd, buffer, 255);
    if (n < 0)
    {
        printf("Error: Failed to receive message from client!\n");
        exit(1);
    }

    //Print the response from the client
    printf("Client: %s", buffer);

    //Close the sockets and exit the program
    close(newsockfd);
    close(sockfd);
    return 0;
}