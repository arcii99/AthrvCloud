//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// Define the proxy server port
#define PROXY_PORT 8888

// Define the maximum length of the HTTP request/response
#define MAX_LENGTH 1024

// Function prototype
void error(char *msg);

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen, n;
    char buffer[MAX_LENGTH];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Check if the user provided the server's IP address
    if (argc < 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(1);
    }

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Initialize the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PROXY_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the address/port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Loop forever waiting for new connections
    while (1) {

        // Accept a new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        // Initialize the buffer
        bzero(buffer, MAX_LENGTH);

        // Read the HTTP request from the client
        n = read(newsockfd, buffer, MAX_LENGTH - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }

        // Extract the hostname from the HTTP request
        char *start = strstr(buffer, "Host: ") + 6;
        char *end = strstr(start, "\r\n");
        char hostname[MAX_LENGTH];
        strncpy(hostname, start, end - start);
        hostname[end - start] = '\0';

        // Get the IP address of the server
        server = gethostbyname(hostname);
        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(1);
        }

        // Initialize the server address structure
        struct sockaddr_in serv_addr;
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr,
              (char *) &serv_addr.sin_addr.s_addr,
              server->h_length);
        serv_addr.sin_port = htons(80);

        // Open a new socket to the server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            error("ERROR opening socket");
        }

        // Connect to the server
        if (connect(server_sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
            error("ERROR connecting");
        }

        // Send the HTTP request to the server
        n = write(server_sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // Initialize the buffer
        bzero(buffer, MAX_LENGTH);

        // Read the HTTP response from the server
        n = read(server_sockfd, buffer, MAX_LENGTH - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }

        // Send the HTTP response to the client
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // Close the connection to the server
        close(server_sockfd);

        // Close the connection to the client
        close(newsockfd);
    }

    // Close the socket
    close(sockfd);
    return 0;
}

void error(char *msg) {
    perror(msg);
    exit(1);
}