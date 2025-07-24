//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80

int main(int argc, char *argv[]) {
    char *ip = argv[1]; // IP address inputted by the user
    struct sockaddr_in server_addr;
    int sockfd, status, port, num_scanned = 0;

    if(argc < 2) {
        printf("Please enter an IP address");
        exit(EXIT_FAILURE);
    }

    // Creating socket file descriptor
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // Loop to scan for open ports
    for(port = 0; port <= 65535; port++) {
        num_scanned++;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip);

        // Connect to the server
        status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if(status == 0) {
            printf("Port %d is open\n", port);
        }

        // Close connection
        close(sockfd);
    }

    printf("Scanning complete! %d ports were scanned\n", num_scanned);

    return 0;
}