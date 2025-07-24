//FormAI DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define RESPONSE "\
HTTP/1.1 200 OK\r\n\
Content-Type: text/html\r\n\
Connection: close\r\n\
\r\n\
<html>\
<head><title>Simple Web Server</title></head>\
<body><h1>Welcome to my Simple Web Server</h1></body>\
</html>"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[4096];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Setup server address configuration
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("Server listening on port %d\n", portno);

    // Accept and handle incoming connections
    clilen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }
        
        // Read client request
        bzero(buffer, 4096);
        n = read(newsockfd, buffer, 4095);
        if (n < 0) {
            perror("ERROR reading from socket");
            continue;
        }

        // Send response
        n = write(newsockfd, RESPONSE, strlen(RESPONSE));
        if (n < 0) {
            perror("ERROR writing to socket");
        }

        // Close client connection
        close(newsockfd);
    }

    // Close server socket
    close(sockfd);
    return 0;
}