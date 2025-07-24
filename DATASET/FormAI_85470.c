//FormAI DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char **argv) {

    int sockfd, newsockfd, len;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Socket creation failed...\n");
        exit(EXIT_FAILURE);
    }
    else {
        fprintf(stdout, "Socket successfully created...\n");
    }

    memset(&servaddr, 0, sizeof(servaddr)); // Clearing the servaddr structure
    
    // Setting the server properties
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding the socket with the server address
    if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        fprintf(stderr, "Socket bind failed...\n");
        exit(EXIT_FAILURE);
    }
    else {
        fprintf(stdout, "Socket successfully binded...\n");
    }

    // Listening for incoming connections
    if(listen(sockfd, 5) != 0) {
        fprintf(stderr, "Listen failed...\n");
        exit(EXIT_FAILURE);
    }
    else {
        fprintf(stdout, "Server listening on port %d...\n", PORT);
    }

    len = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len); // Accept the incoming connection
    if (newsockfd < 0) {
        fprintf(stderr, "Server accept failed...\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Connection accepted from %s:%d\n", 
            inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    // Send welcome message to the client
    char *welcome_msg = "Welcome to the server!";
    send(newsockfd, welcome_msg, strlen(welcome_msg), 0);

    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clearing the buffer

        // Receive data from client
        if(recv(newsockfd, buffer, 1024, 0) < 0) {
            fprintf(stderr, "Server receive failed...\n");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "exit", 4) == 0) {
            fprintf(stdout, "Client disconnected...\n");
            break;
        }

        fprintf(stdout, "Client: %s\n", buffer);

        // Send message to the client
        char *msg = "Message received!";
        send(newsockfd, msg, strlen(msg), 0);
    }

    // Close the sockets
    close(sockfd);
    close(newsockfd);

    fprintf(stdout, "Server closed...\n");

    return 0;
}