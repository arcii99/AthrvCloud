//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Define variables 
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Ensure port number is provided as argument
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create a new socket 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Clear the server address before use
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Set up the server address 
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for clients 
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept a new connection 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // Clear the buffer before use 
    bzero(buffer,256);

    // Read from the socket into the buffer 
    n = read(newsockfd,buffer,255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print the message from the client 
    printf("Here is the message: %s\n",buffer);

    // Write a message back to the client 
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Close the sockets 
    close(newsockfd);
    close(sockfd);

    return 0;
}