//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_MSG_LENGTH 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Assigning IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding the socket
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        error("Socket binding failed");
    }

    // Listening for incoming connections
    if ((listen(sockfd, 5)) != 0) {
        error("Listen failed");
    }

    printf("Server is listening on port %d\n", PORT);
    socklen_t len = sizeof(cliaddr);

    // Accepting connections from clients
    connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd < 0) {
        error("Accept failed");
    }

    char buffer[MAX_MSG_LENGTH];
    int n;

    // Receiving message from client
    n = read(connfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Received message from client: %s", buffer);

    // Sending a response back to client
    char* msg = "Hello from server!";
    n = write(connfd, msg, strlen(msg));
    if (n < 0) {
        error("Error writing to socket");
    }

    // Closing sockets
    close(connfd);
    close(sockfd);

    return 0;
}