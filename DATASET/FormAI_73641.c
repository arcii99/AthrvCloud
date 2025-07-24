//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define IP_ADDR "192.168.1."  // Replace with your IP address prefix
#define TIMEOUT 5  // Wait 5 seconds for response

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    printf("Scanning network for active devices...\n");

    struct sockaddr_in server;
    server.sin_family = AF_INET;  // IPv4
    server.sin_port = htons(80);  // HTTP
    char ip[16];
    bool found_device = false;
    int num_devices = 0;

    for (int i = 1; i <= 255; i++) {  // Scan all IP addresses in range
        sprintf(ip, "%s%d", IP_ADDR, i);
        server.sin_addr.s_addr = inet_addr(ip);  // Convert IP address to binary

        if (connect(sockfd, (struct sockaddr*) &server, sizeof(server)) != -1) {
            printf("%s - Device found\n", ip);
            found_device = true;
            num_devices++;
        } else {
            printf("%s - No device found\n", ip);
        }

        sleep(1);  // Wait for 1 second to avoid overwhelming the network
    }

    if (!found_device) {
        printf("No devices found on network.\n");
    } else {
        printf("\n%d devices found on network.\n", num_devices);
    }

    close(sockfd);
    return 0;
}