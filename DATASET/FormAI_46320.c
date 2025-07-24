//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// Function to check if a port is open or closed
int is_port_open(const char* host, int port) {
    struct sockaddr_in addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        return 0;
    }

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);

    int conn = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    close(sockfd);

    if(conn == -1) {
        return 0;
    }

    return 1;
}

// Function to scan for open ports
int scan_ports(const char* host, int start_port, int end_port) {
    for(int port=start_port; port<=end_port; port++) {
        if(is_port_open(host, port)) {
            printf("Port %d is open\n", port);
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    const char* host = "localhost";
    int start_port = 0;
    int end_port = 65535;

    scan_ports(host, start_port, end_port);

    return 0;
}