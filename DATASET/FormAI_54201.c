//FormAI DATASET v1.0 Category: Simple Web Server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int portno = 8080; // port number
    socklen_t clilen;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        perror("ERROR opening socket");

    // Fill in server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to local address
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) 
        perror("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while(1) {
        // Accept a connection
        newsockfd = accept(sockfd, 
            (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) 
            perror("ERROR on accept");

        // Read request from the client
        char buffer[1024];
        bzero(buffer, 1024);
        read(newsockfd, buffer, 1023);

        // Parse request
        char *token = strtok(buffer, " ");
        char method[255], path[255], protocol[255];
        strcpy(method, token);
        token = strtok(NULL, " ");
        strcpy(path, token);
        token = strtok(NULL, " ");
        strcpy(protocol, token);

        // Get file path
        char filepath[255] = ".";
        strcat(filepath, path);

        // Send response to the client
        FILE *file = fopen(filepath, "r");
        if (file == NULL) {
            // File not found
            char response[255] = "HTTP/1.1 404 Not Found\r\n";
            send(newsockfd, response, strlen(response), 0);
        } else {
            // File found
            char response[255] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
            send(newsockfd, response, strlen(response), 0);
            
            int fd = fileno(file);
            if (fd < 0) 
                perror("ERROR getting file descriptor");

            int n;
            char buf[1024];
            while ((n = read(fd, buf, 1023)) > 0) {
                send(newsockfd, buf, n, 0);
            }
            fclose(file);
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}