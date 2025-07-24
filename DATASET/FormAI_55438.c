//FormAI DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT_NUMBER 65535
#define MIN_PORT_NUMBER 1

void scan_port(char *ip, int port_number);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(0);
    }
    char *ip_address = argv[1];
    printf("Scanning ports on %s...\n", ip_address);
    for (int i = MIN_PORT_NUMBER; i <= MAX_PORT_NUMBER; i++) {
        scan_port(ip_address, i);
    }
    printf("Scan complete.\n");
    return 0;
}

void scan_port(char *ip, int port_number) {
    int sockfd, result;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket.");
        exit(1);
    }
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_aton(ip, &server_addr.sin_addr) == 0) {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
    result = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (result == 0) {
        printf("Port %d is open.\n", port_number);
        close(sockfd);
    }
}