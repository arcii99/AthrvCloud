//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORT 65535 // maximum port number to be scanned
#define MAX_BUFFER_SIZE 1024 // maximum buffer size for receiving data

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    printf("Welcome to the cheerful port scanner!\n");
    printf("We will scan the first %d ports of IP address %s\n", MAX_PORT, argv[1]);

    int sock_fd; // socket file descriptor
    struct sockaddr_in target_ip;
    char buffer[MAX_BUFFER_SIZE];
    memset(&target_ip, 0, sizeof(target_ip)); // zero out the target_ip structure

    // fill in the target_ip structure with the IP address and TCP protocol
    target_ip.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(target_ip.sin_addr));

    for (int i = 1; i <= MAX_PORT; i++) {
        // create a socket file descriptor
        if ((sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            perror("socket()");
            exit(1);
        }

        // fill in the target_ip structure with the current port number
        target_ip.sin_port = htons(i);

        // connect to the target IP address and port number
        if (connect(sock_fd, (struct sockaddr*) &target_ip, sizeof(target_ip)) == 0) {
            printf("Port %d is open!\n", i);
        }

        // close the socket file descriptor
        close(sock_fd);
    }

    printf("Scanning completed! Have a great day :)\n");

    return 0;
}