//FormAI DATASET v1.0 Category: Chat server ; Style: single-threaded
/*
 *  A simple C chat server program
 *
 *  Uses the socket library to accept incoming client connections and
 *  read/write data between them.
 *
 *  This program is single-threaded, meaning it only handles one
 *  connection at a time.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 256
#define PORT_NUMBER 12345

int main()
{
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // create a socket for incoming connections
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set up server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT_NUMBER);

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) { // Keep the server running
        printf("Waiting for client connections on port %d...\n", PORT_NUMBER);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Client connected!\n");

        // read and write data
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            n = read(newsockfd, buffer, BUFFER_SIZE-1);
            if (n < 0) {
                perror("ERROR reading from socket");
                break;
            }
            if (n == 0) { // client disconnected
                printf("Client disconnected!\n");
                break;
            }
            printf("Received message from client: %s\n", buffer);
            n = write(newsockfd, "Server received your message", strlen("Server received your message"));
            if (n < 0) {
                perror("ERROR writing to socket");
                break;
            }
        }
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}