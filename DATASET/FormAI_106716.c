//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        exit(1);
    }

    // Set server address properties
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 12345;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        printf("ERROR on binding\n");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        // Accept connection from client
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("ERROR on accept\n");
            exit(1);
        }

        // Read from socket
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            printf("ERROR reading from socket\n");
            exit(1);
        }

        // Print message from client
        printf("Here is the message: %s\n", buffer);

        // Write to socket
        n = write(newsockfd, "I got your message", 18);
        if (n < 0) {
            printf("ERROR writing to socket\n");
            exit(1);
        }

        // Close socket
        close(newsockfd);
    }

    // Close main socket
    close(sockfd);
    return 0;
}