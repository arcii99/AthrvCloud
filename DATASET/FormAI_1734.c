//FormAI DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // ensure correct usage
    if (argc != 2) {
        printf("Usage: %s [IP Address]\n", argv[0]);
        return 1;
    }

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    // set timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        printf("Failed to set timeout\n");
    }

    // assign IP and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    // scan ports
    for (int port = 1; port <= 65535; port++) {
        server_address.sin_port = htons(port);

        // attempt connection
        if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
            continue;
        } else {
            printf("Port %d is open\n", port);
        }
    }

    close(sock);
    return 0;
}