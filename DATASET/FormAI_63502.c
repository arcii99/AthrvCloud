//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

/* Function to handle client connection */
void handleClient(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int n;

    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        printf("Error reading from socket\n");
        return;
    }

    printf("Received message: %s\n", buffer);

    /* Reverse the message */
    int length = strlen(buffer);
    for (int i = 0; i < length / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }

    n = write(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        printf("Error writing to socket\n");
        return;
    }
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, clientaddr;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    /* Initialize server address */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    /* Bind socket to server address */
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error binding socket to server address\n");
        return 1;
    }

    /* Listen for incoming connections */
    if (listen(sockfd, 5) < 0) {
        printf("Error listening for connections\n");
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        /* Accept incoming connection */
        socklen_t clientaddr_len = sizeof(clientaddr);
        connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
        if (connfd < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        /* Convert client IP address to string */
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientaddr.sin_addr, client_ip, sizeof(client_ip));
        printf("Accepted connection from %s:%d\n", client_ip, ntohs(clientaddr.sin_port));

        /* Handle client connection */
        handleClient(connfd);

        close(connfd);
    }
    return 0;
}