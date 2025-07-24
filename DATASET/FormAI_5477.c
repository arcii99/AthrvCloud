//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 9001 // Port number

int main()
{
    int sockfd, newsockfd;
    socklen_t clilen;

    char buffer[256], startmsg[30] = "Welcome to the server!";
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Socket creation

    if (sockfd < 0) // If socket creation fails
    {
        printf("Error creating socket. Exiting...\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr)); // Clearing the server address structure

    serv_addr.sin_family = AF_INET; // IPv4 protocol family
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Accepting any incoming IP address
    serv_addr.sin_port = htons(PORT); // Converting port number to network byte order

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // Binding socket to IP address and port number
    {
        printf("Error binding. Exiting...\n");
        exit(1);
    }

    listen(sockfd, 5); // Listen for incoming connections, maximum 5

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); // Accept incoming connection request

    if (newsockfd < 0) // If connection acceptance fails
    {
        printf("Error accepting connection. Exiting...\n");
        exit(1);
    }

    send(newsockfd, startmsg, 30, 0); // Send welcome message to client

    while (1) // Infinite loop to keep server running
    {
        int n = 0;
        bzero(buffer, 256); // Clear buffer

        n = recv(newsockfd, buffer, 255, 0); // Receive message from client

        if (n < 0) // If receive fails
        {
            printf("Error receiving message. Exiting...\n");
            exit(1);
        }

        printf("Message from client: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) // If client wants to exit
        {
            close(sockfd); // Close socket
            close(newsockfd); // Close new socket
            printf("Closing server...\n");
            break; // Exit infinite loop
        }

        char reply[256];
        sprintf(reply, "Server: %s\n", buffer); // Append "Server: " to received message

        send(newsockfd, reply, strlen(reply), 0); // Send response to client
    }

    return 0;
}