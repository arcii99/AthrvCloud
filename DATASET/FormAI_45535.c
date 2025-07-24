//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    }

    int socket_desc;
    struct sockaddr_in target;

    // Create socket descriptor
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return -1;
    }

    // Target IP and port
    target.sin_addr.s_addr = inet_addr(argv[1]);
    target.sin_family = AF_INET;

    // Scan ports 1-65535
    for (int port = 1; port <= 65535; port++) {
        // Set target port
        target.sin_port = htons(port);

        // Connect to port
        if (connect(socket_desc, (struct sockaddr *)&target, sizeof(target)) < 0) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
        }

        // Close connection
        close(socket_desc);
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    }

    return 0;
}