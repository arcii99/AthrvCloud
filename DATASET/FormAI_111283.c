//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

// Define maximum and minimum port values
#define MIN_PORT 1
#define MAX_PORT 65535

// Define timeout for socket connections
#define TIMEOUT 1

// Function to print help information
void print_help(char *prog_name) {
    printf("Usage: %s <hostname/IP address> [options]\n", prog_name);
    printf("\nOptions:\n");
    printf("  -p <port range>\tScan a specific range of ports (format: <start_port>-<end_port>)\n");
    printf("  -t <timeout>\t\tSet the timeout for socket connections (default: %d seconds)\n", TIMEOUT);
}

int main(int argc, char *argv[]) {
    // Check if hostname/IP address is provided
    if (argc < 2) {
        printf("Error: Missing hostname/IP address argument.\n");
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize variables
    char *hostname = argv[1];
    int start_port = MIN_PORT;
    int end_port = MAX_PORT;
    int timeout = TIMEOUT;

    // Parse command-line options
    int opt;
    while ((opt = getopt(argc, argv, "p:t:h")) != -1) {
        switch (opt) {
            case 'p':
                // Parse port range
                sscanf(optarg, "%d-%d", &start_port, &end_port);
                if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
                    printf("Error: Invalid port range.\n");
                    print_help(argv[0]);
                    exit(EXIT_FAILURE);
                }
                break;
            case 't':
                // Set timeout
                timeout = atoi(optarg);
                break;
            case 'h':
            default:
                // Print help information and exit
                print_help(argv[0]);
                exit(EXIT_SUCCESS);
        }
    }

    // Resolve hostname/IP address
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    int status = getaddrinfo(hostname, NULL, &hints, &res);
    if (status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // Loop through all ports in the specified range
    for (int port = start_port; port <= end_port; port++) {
        // Create socket
        int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sockfd == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Set socket timeout
        struct timeval tv;
        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Set socket address
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = ((struct sockaddr_in *)res->ai_addr)->sin_addr.s_addr;

        // Connect to socket
        if (connect(sockfd, (struct sockaddr*)&addr, sizeof addr) == 0) {
            // Port is open
            printf("Port %d is open.\n", port);
        }

        // Close socket
        close(sockfd);
    }

    // Free address information
    freeaddrinfo(res);

    return 0;
}