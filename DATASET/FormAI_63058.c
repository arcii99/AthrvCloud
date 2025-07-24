//FormAI DATASET v1.0 Category: Client Server Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char* argv[]) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Set server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        uint16_t len;
        char buffer[MAXLINE];

        // Accept incoming connection
        if ((connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read message from client
        int n = read(connfd, buffer, sizeof(buffer));
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        // Send response
        char* response = "Hello from server";
        write(connfd, response, strlen(response));
        
        // Close connection
        close(connfd);
    }
    return 0;
}