//FormAI DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// Function to connect to the given port on the IP address
void connect_to_port(char* ip_address, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set the IP address and port to connect
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Invalid IP address/ Address not supported");
        return;
    }

    // Connect to the given IP address and port
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    printf("[ + ] Connection established on port %d\n", port);

    // Close the socket
    close(sockfd);
}

int main(int argc, char** argv) {
    // Check if the IP address is given
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 0;
    }

    // Get the IP address from the command line arguments
    char* ip_address = argv[1];

    // Loop over all the common ports and connect to them
    printf("Scanning ports on %s...\n", ip_address);
    for (int port = 1; port <= 65535; port++) {
        connect_to_port(ip_address, port);
    }

    return 0;
}