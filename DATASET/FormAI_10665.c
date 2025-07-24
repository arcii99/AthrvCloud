//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Define the port number for the QoS monitor
#define PORT 8080

// Define the maximum buffer size for messages
#define BUFFER_SIZE 256

int main()
{
    int sockfd, newsockfd, clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create a socket for communication
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket with the server address structure
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error on binding");
        exit(1);
    }

    // Listen for incoming client connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Starting Network Quality of Service (QoS) monitor..\n");

    // Loop infinitely to accept and handle incoming client connections
    while (1)
    {
        // Accept a new client connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        // Check if the new client connection was accepted successfully
        if (newsockfd < 0)
        {
            perror("Error on accept");
            exit(1);
        }

        // Read the message sent by the client
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);

        if (n < 0)
        {
            perror("Error reading from socket");
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        // Parse the message to determine the QoS status
        if (strcmp(buffer, "low") == 0)
        {
            printf("QoS Status: Low\n");
        }
        else if (strcmp(buffer, "medium") == 0)
        {
            printf("QoS Status: Medium\n");
        }
        else if (strcmp(buffer, "high") == 0)
        {
            printf("QoS Status: High\n");
        }
        else
        {
            printf("Invalid QoS status received: %s\n", buffer);
        }

        // Close the client socket
        close(newsockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}