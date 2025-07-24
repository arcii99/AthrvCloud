//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_RANGE 1000 // Maximum range of ports to scan

// Function to print the usage instructions of the program
void usage(char *program_name) {
    printf("Usage: %s <IP address>\n", program_name);
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if(argc != 2) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get server IP
    struct in_addr serv_ip;
    inet_aton(argv[1], &serv_ip);

    // Scan for open ports
    for(int port=0; port <= PORT_RANGE; port++) {
        // Create socket address
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr = serv_ip;

        // Try to connect to the specified port
        if(connect(sfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) != -1) {
            printf("Port %d is open.\n", port);
        }
    }

    // Close the socket
    close(sfd);

    return EXIT_SUCCESS;
}