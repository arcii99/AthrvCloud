//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
// This is a TCP/IP Programming example that demonstrates socket connections between a client and a server
// The program receives a message from the client, converts it to uppercase, and sends it back to the client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080 // Port number for socket connection

int main() {
    int sockfd, newsockfd, n; // File descriptors for sockets
    char buffer[1024]; // Buffer for storing message
    
    // Creating socket file descriptor
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Configuring socket settings
    struct sockaddr_in servaddr, clientaddr;
    int addrlen = sizeof(servaddr);

    memset(&servaddr, 0, addrlen);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    // Binding socket to IP address and port number
    if(bind(sockfd, (struct sockaddr *)&servaddr, addrlen) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }
    
    // Listening for client connection
    if(listen(sockfd, 5) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    
    // Accepting client connection
    if((newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, (socklen_t*)&addrlen)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    
    // Receiving message from client
    memset(buffer, 0, sizeof(buffer));
    n = read(newsockfd, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);
    
    // Converting message to uppercase
    for(int i = 0; buffer[i]; i++) {
        buffer[i] = toupper(buffer[i]);
    }
    
    // Sending modified message back to client
    write(newsockfd, buffer, strlen(buffer));
    printf("Modified message sent to client: %s\n", buffer);
    
    // Closing sockets
    close(newsockfd);
    close(sockfd);
    return 0;
}