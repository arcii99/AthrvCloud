//FormAI DATASET v1.0 Category: Networking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_LINE 1024

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Clearing servaddr and cliaddr
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding socket to address
    if (bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(sockfd, 5) != 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        socklen_t len = sizeof(cliaddr);
        // Accepting incoming connection
        connfd = accept(sockfd, (struct sockaddr*) &cliaddr, &len);
        if (connfd < 0) {
            perror("accept failed");
            continue;
        }

        char hello[MAX_LINE] = "Hello from server!";
        send(connfd, hello, strlen(hello), 0);
        printf("Message sent to client: %s\n", hello);

        char buffer[MAX_LINE];
        memset(buffer, 0, sizeof(buffer));
        int valread = read(connfd, buffer, MAX_LINE);
        printf("Message received from client: %s\n", buffer);

        close(connfd);
    }

    return 0;
}