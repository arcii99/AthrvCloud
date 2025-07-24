//FormAI DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_PORT 65535
#define TIMEOUT 5

// function to check if the port is open
int is_port_open(char *server_ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(server_ip);

    // set the timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));

    // check if the connection was successful
    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == 0) {
        close(sockfd);
        return 1;
    } else {
        close(sockfd);
        return 0;
    }
}

int main(int argc, char *argv[]) {

    // check if the user has provided an argument
    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    // get the server IP address from the user
    char *server_ip = argv[1];

    // scan all the ports and print the open ones
    for (int port = 1; port <= MAX_PORT; port++) {
        if (is_port_open(server_ip, port)) {
            printf("Port %d is open\n", port);
        }
    }

    return 0;
}