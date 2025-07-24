//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PORTS 1000 // maximum number of ports to scan
#define BUFFER_SIZE 1024 // size of buffer to receive data

int main(int argc, char *argv[]) {
    if (argc != 2) { // check if user provided IP address to scan
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind the socket");
        exit(EXIT_FAILURE);
    }

    // get list of open ports
    printf("Scanning %s...\n", ip_address);
    for (int port = 1; port <= MAX_PORTS; port++) {
        struct sockaddr_in remote_addr;
        bzero(&remote_addr, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(port);
        remote_addr.sin_addr.s_addr = inet_addr(ip_address);

        int connfd = socket(AF_INET, SOCK_STREAM, 0);
        if (connfd < 0) {
            perror("Failed to create socket");
            exit(EXIT_FAILURE);
        }

        // try to connect to the port
        if (connect(connfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == 0) {
            printf("Port %d is open.\n", port);
        }

        // close socket
        close(connfd);
    }

    // close socket
    close(sockfd);

    return 0;
}