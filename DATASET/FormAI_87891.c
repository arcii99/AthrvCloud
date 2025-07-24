//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to check if a specified port is open on the target host
bool is_port_open(const char* target, int port) {
    struct sockaddr_in addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return false;
    }

    // Set target IP and port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target);
    addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&addr, sizeof addr) < 0) {
        close(sock);
        return false;
    }

    // Port is open!
    close(sock);    
    return true;
}

int main(int argc, char* argv[]) {
    const char* target = "127.0.0.1";
    bool ports[65536] = { false };

    // Check if a target IP has been specified
    if (argc == 2) {
        target = argv[1];
    }

    // Scan all ports in range
    for (int port = 1; port <= 65535; ++port) {
        if (is_port_open(target, port)) {
            printf("Port %d on %s is open.\n", port, target);
            ports[port] = true;
        }
    }

    // Print summary of open ports
    printf("---- Open Ports Summary ----\n");
    for (int port = 1; port <= 65535; ++port) {
        if (ports[port]) {
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}