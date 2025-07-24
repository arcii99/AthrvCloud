//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535 // Maximum number of ports to scan

// Function to check if a port is open
int portIsOpen(char *host, int port) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Could not create socket");
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(host);
    address.sin_port = htons(port);

    // Try to connect to the port
    if(connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        close(sock);
        return 0;
    }

    // If connected successfully, close the connection and return 1
    close(sock);
    return 1;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int open_ports[MAX_PORTS] = { 0 }; // Initialize all elements to 0
    int num_open_ports = 0;

    printf("Scanning ports of %s...\n", host);
    for(int port = 1; port <= MAX_PORTS; port++) {
        if(portIsOpen(host, port)) {
            printf("Port %d is open\n", port);
            open_ports[num_open_ports] = port;
            num_open_ports++;
        }
    }

    printf("Found %d open port(s) on %s:\n", num_open_ports, host);
    for(int i = 0; i < num_open_ports; i++) {
        printf("%d\n", open_ports[i]);
    }

    return 0;
}