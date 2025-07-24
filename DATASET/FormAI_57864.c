//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define PORT 21
#define SA struct sockaddr

// Function to read server response
void readServerResponse(int sockfd)
{
    char buffer[MAX];
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server Response: %s\n", buffer);
}

// Function to build the FTP client
void buildClient(int sockfd)
{
    char buffer[MAX];
    int n;
    while (1) {
        bzero(buffer, sizeof(buffer));
        printf("Enter the FTP command: ");
        n = 0;
        while ((buffer[n++] = getchar()) != '\n')
            ;

        write(sockfd, buffer, sizeof(buffer));
        
        // Commands to terminate the client
        if ((strncmp(buffer, "quit", 4)) == 0) {
            printf("Client exit...\n");
            break;
        }

        // Read server response
        readServerResponse(sockfd);
    }
}

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created...\n");
    bzero(&servaddr, sizeof(servaddr));

    // Assigning IP and PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connecting the client to server
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed...\n");
        exit(0);
    }
    else
        printf("Connected to the server...\n");

    // Start building command line client
    buildClient(sockfd);

    // Close the socket and exit
    close(sockfd);
    return 0;
}