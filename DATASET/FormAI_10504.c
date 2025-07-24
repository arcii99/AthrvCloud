//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MIN_PORT_NUMBER 0
#define MAX_PORT_NUMBER 65535

// Function declarations
void print_usage();
int is_valid_ip_address(char* ip_address);
int scan_port(char* ip_address, int port_number);

int main(int argc, char **argv) {
    if (argc != 2) { // Must provide 1 argument (IP Address)
        print_usage();
        return 1;
    }

    char* ip_address = argv[1];
    if (!is_valid_ip_address(ip_address)) { // Argument must be a valid IP Address
        printf("Invalid IP Address: %s\n", ip_address);
        print_usage();
        return 1;
    }

    printf("Scanning wireless network for open ports on IP address %s...\n", ip_address);

    int i;
    for (i = MIN_PORT_NUMBER; i <= MAX_PORT_NUMBER; i++) {
        int port_status = scan_port(ip_address, i);
        if (port_status == 0) {
            printf("Port %d is open\n", i);
        }
    }

    printf("Scan completed\n");

    return 0;
}

// Function to print program usage
void print_usage() {
    printf("Wireless Network Scanner\n");
    printf("Usage: scanner <ip_address>\n");
    printf("Example: scanner 192.168.0.1\n");
}

// Function to check if a given string is a valid IP Address
int is_valid_ip_address(char* ip_address) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    return result != 0;
}

// Function to scan a given port number of a given IP Address
int scan_port(char* ip_address, int port_number) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port_number);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket\n");
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        printf("Could not set receive timeout on socket\n");
        return -1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        printf("Could not set send timeout on socket\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}