//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_BACKLOG 100

/**
 * function to create a socket and bind it to the specified port
 * @param port - port number to which socket is bound
 * @return - returns the socket file descriptor
 */
int createAndBindSocket(int port) {
    int serverFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverFd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int optval = 1;
    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // bind socket to specified port
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress))) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // start listening on the socket
    if (listen(serverFd, MAX_BACKLOG)) {
        perror("Failed to start listening on socket");
        exit(EXIT_FAILURE);
    }

    return serverFd;
}

/**
 * function to measure the network quality of service
 * @param serverFd - socket file descriptor on which server is listening for incoming connections
 */
void measureQoS(int serverFd) {
    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);

        // accept incoming connection
        int clientFd = accept(serverFd, (struct sockaddr *) &clientAddress, &clientAddressLen);
        if (clientFd == -1) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // receive data from client
        char buffer[MAX_BUFFER_SIZE];
        int numBytesReceived = recv(clientFd, buffer, MAX_BUFFER_SIZE, 0);
        if (numBytesReceived == -1) {
            perror("Failed to receive data from client");
            exit(EXIT_FAILURE);
        }

        // send response back to client
        int numBytesSent = send(clientFd, buffer, numBytesReceived, 0);
        if (numBytesSent == -1) {
            perror("Failed to send data to client");
            exit(EXIT_FAILURE);
        }

        close(clientFd);
    }
}

int main() {
    int port = 8080;
    int serverFd = createAndBindSocket(port);
    printf("Server listening on port %d...\n", port);
    measureQoS(serverFd);
    return 0;
}