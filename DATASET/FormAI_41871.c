//FormAI DATASET v1.0 Category: Socket programming ; Style: intelligent
/* A simple TCP Echo Server using Sockets in C
 * This program listens on a port for incoming connections from clients.
 * When a client connects, it receives a message from the client
 * and sends it back to the client
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    /* Create a TCP socket */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Setup server address */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    /* Bind the socket to the server address */
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    /* Wait for incoming connections from clients */
    listen(sockfd, 5);
    printf("Server listening on port 8080...\n");

    /* Accept incoming connections */
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
        perror("ERROR on accept");
        exit(1);
    }
    printf("Client connected\n");

    /* Echo messages back to client */
    char buffer[256];
    int n;
    while (1)
    {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Message from client: %s", buffer);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
        {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    /* Close sockets */
    close(newsockfd);
    close(sockfd);

    return 0;
}