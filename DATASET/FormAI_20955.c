//FormAI DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // check if enough args are provided
    if (argc < 2) {
        printf("Please provide at least one target IP address.\n");
        return 0;
    }
    // create socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Could not create socket.\n");
        return 1;
    }
    // set socket options
    int timeout = 5000; // 5 seconds timeout
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        printf("Could not set receive timeout.\n");
        return 1;
    }
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        printf("Could not set send timeout.\n");
        return 1;
    }
    // scan each target IP address
    for (int i = 1; i < argc; i++) {
        // resolve target IP address
        struct sockaddr_in target;
        memset(&target, 0, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(argv[i]);
        // loop through each port number
        for (int port = 1; port <= 65535; port++) {
            // set target port number
            target.sin_port = htons(port);
            // connect to target socket
            if (connect(sock, (struct sockaddr*)&target, sizeof(target)) >= 0) {
                printf("%s:%d is open.\n", argv[i], port);
            }
        }
    }
    // close socket
    close(sock);
    // done
    return 0;
}