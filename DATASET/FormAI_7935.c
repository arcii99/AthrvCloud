//FormAI DATASET v1.0 Category: Networking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd, client_len, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;

    //1. Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    //2. Binding the socket to the IP address and port number
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket to IP address and port number.");
    }

    //3. Listening for incoming connections
    if (listen(sockfd, 5) < 0) {
        error("Error listening for incoming connections.");
    }

    printf("Server is listening on port %d...\n", PORT);

    //4. Accepting a client connection
    client_len = sizeof(client_address);
    newsockfd = accept(sockfd, (struct sockaddr *) &client_address, (socklen_t *) &client_len);
    if (newsockfd < 0) {
        error("Error accepting client connection.");
    }

    printf("Incoming client connection from %s:%d...\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    //5. Reading from and writing to the client
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("Error reading from client.");
        } else if (n == 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received message from client: %s\n", buffer);

        n = write(newsockfd, "Server has received your message.", 34);
        if (n < 0) {
            error("Error writing to client.");
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}