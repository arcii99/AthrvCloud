//FormAI DATASET v1.0 Category: Client Server Application ; Style: happy
// Happy C Client Server Application Example
// Let's create a chat application between a client and a server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    printf("Welcome to my Happy Client Server Application!\n\n");

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if (sockfd < 0) 
    {
        printf("Error opening socket.\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr)); // clear serv_addr

    portno = 4444; // set port number

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // bind socket
    {
        printf("Error on binding.\n");
        exit(1);
    }

    listen(sockfd, 5); // listen for incoming connections

    printf("Server waiting for incoming connections...\n");

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); // accept connection
    if (newsockfd < 0) 
    {
        printf("Error on accept.\n");
        exit(1);
    }

    printf("Client connected. You can now chat!\n\n");

    while(1) // chat loop
    {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255); // read message from client
        if (n < 0) 
        {
            printf("Error reading from socket.\n");
            exit(1);
        }

        printf("Client: %s\n", buffer);

        bzero(buffer, 256);
        printf("You: ");
        fgets(buffer, 255, stdin); // get message from user
        n = write(newsockfd, buffer, strlen(buffer)); // send message to client
        if (n < 0) 
        {
            printf("Error writing to socket.\n");
            exit(1);
        }

        if (strcmp(buffer, "bye\n") == 0) // end chat if user types "bye"
            break;
    }

    printf("\nGoodbye! Chat ended.\n");

    close(newsockfd);
    close(sockfd);

    return 0;
}