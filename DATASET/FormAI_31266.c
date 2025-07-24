//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h> 
#include <stdlib.h> // for exit()
#include <unistd.h> // for close()
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_PORTS 100

void print_banner() {
    printf("**********************************\n");
    printf("*         PORT SCANNER           *\n");
    printf("**********************************\n\n");
}

void usage(char *filename) {
    printf("Usage: %s <ip_address>\n", filename);
    printf("Example: %s 127.0.0.1\n", filename);
}

int main(int argc, char **argv) {
    int sockfd, port, i;
    char *ip_address;
    struct sockaddr_in target;

    // Check if IP address is provided as argument
    if (argc != 2) {
        usage(argv[0]);
        exit(1);
    }

    // Get IP address from command line argument
    ip_address = argv[1];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Fill the target struct
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    print_banner();

    // Scan the ports
    for (port=1; port <= MAX_PORTS; port++) {

        target.sin_port = htons(port);

        // Try to connect to the port
        if (connect(sockfd, (struct sockaddr*)&target, sizeof(target)) == 0) {
            printf("[+] Port %d is open.\n", port);
        }
        // Close the connection
        close(sockfd);
    }

    printf("\n[+] Scan complete.\n");

    return 0;
}