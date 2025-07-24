//FormAI DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 5000 // define the port number

int main() {
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;
    char buffer[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket

    if (sockfd == -1) {
        printf("Failed to create socket\n");
        exit(0);
    }
    else {
        printf("Socket successfully created\n");
    }

    // clear servaddr struct memory
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, address family and port number
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // binding newly created socket to given IP and verification 
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else {
        printf("Socket successfully binded\n");
    }

    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed\n"); 
        exit(0); 
    } 
    else{
        printf("Server listening..\n");
    }
        
    socklen_t len = sizeof(cli);

    // Accept the client connections
    connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else {
        printf("server accepts the client...\n");
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        read(connfd, buffer, sizeof(buffer)); // read the message from client
        printf("Message from client: %s", buffer); 
        bzero(buffer, sizeof(buffer));

        printf("Enter the message to send to the client: ");
        int n = 0;
        while ((buffer[n++] = getchar()) != '\n');

        write(connfd, buffer, sizeof(buffer)); // send the message to client

        if (strncmp("exit", buffer, 4) == 0) {
            printf("Server exiting...");
            break;
        }
    }

    // close the socket
    close(sockfd);

    return 0;
}