//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORTS 100000

struct port_scan_result {
    int port;
    int status; // 0 - closed, 1 - open
};

int scan_port(char *ip_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        printf("Failed to create socket for port %d\n", port);
        return 0;
    }

    // Set socket timeout to 1 second
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    int status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(status == 0) {
        // Port is open
        close(sockfd);
        return 1;
    } else {
        // Port is closed or there was an error
        close(sockfd);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];

    printf("Scanning ports for %s...\n", ip_address);

    struct port_scan_result results[MAX_PORTS];
    int num_results = 0;

    for(int i = 1; i <= MAX_PORTS; i++) {
        int status = scan_port(ip_address, i);

        if(status == 1) {
            printf("Port %d is open\n", i);
            results[num_results].port = i;
            results[num_results].status = 1;
            num_results++;
        } else {
            printf("Port %d is closed\n", i);
        }
    }

    printf("Scan complete. Found %d open ports.\n", num_results);

    return 0;
}