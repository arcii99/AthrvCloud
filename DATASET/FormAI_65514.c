//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg); // Print error message using perror
    exit(1); // Exit program
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create TCP socket

    if (sockfd < 0) // Check for errors
        error("ERROR opening socket");

    memset((char *) &serv_addr, 0, sizeof(serv_addr)); 

    portno = atoi(argv[1]); // Get port number from command line argument

    serv_addr.sin_family = AF_INET; // Set address family
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Set IP address
    serv_addr.sin_port = htons(portno); // Set port number

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // Bind socket to address
        error("ERROR on binding");

    listen(sockfd,5); // Listen for incoming connections

    clilen = sizeof(cli_addr); 

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); // Accept incoming connection from client

        if (newsockfd < 0) // Check for errors
            error("ERROR on accept");

        memset(buffer, 0, 1024); // Clear buffer

        n = read(newsockfd,buffer,1023); // Read request from client

        if (n < 0) // Check for errors
            error("ERROR reading from socket");

        printf("Here is the message: %s\n",buffer); // Print request message

        n = write(newsockfd,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>SURPRISE! You successfully run a C Simple Web Server! 🎉</h1></body></html>", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>SURPRISE! You successfully run a C Simple Web Server! 🎉</h1></body></html>")); // Send response to client

        if (n < 0) // Check for errors
            error("ERROR writing to socket");

        close(newsockfd); // Close socket
    }

    close(sockfd); // Close master socket
    
    return 0; // Return from main
}