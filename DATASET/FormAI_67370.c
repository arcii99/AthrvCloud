//FormAI DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT 65535

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [IP address]\n", argv[0]);
        return 1;
    }

    int i, port;
    struct sockaddr_in server;
    char *ip = argv[1];

    // Initialize the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server information
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    memset(&(server.sin_zero), 0, 8);

    // Loop over all ports and check if they are open
    for (port = 1; port <= MAX_PORT; port++) {
        server.sin_port = htons(port);

        // Connect to the port
        int status = connect(sockfd, (struct sockaddr *)&server, sizeof(server));

        // Print the open port number
        if (status == 0) {
            printf("Port %d is open\n", port);
        }

        // Sleep for a short while to avoid overwhelming the server
        usleep(100);
    }

    // Close the socket
    close(sockfd);

    return 0;
}