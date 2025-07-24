//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_IP_ADDRESS_LENGTH 16
#define MAX_PORT_NUMBER 65535

void print_usage() {
    printf("Usage: wireless_network_scanner <subnet>\n");
    printf("Example: wireless_network_scanner 192.168.1\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 0;
    }

    char *subnet = argv[1];

    printf("Scanning for wireless network devices on subnet %s.*\n", subnet);

    int total_found = 0;
    for (int i = 1; i <= MAX_PORT_NUMBER; i++) {
        char ip_address[MAX_IP_ADDRESS_LENGTH];
        sprintf(ip_address, "%s.%d", subnet, i);

        struct sockaddr_in address;
        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_port = htons(80);
        inet_pton(AF_INET, ip_address, &address.sin_addr);

        int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (socket_fd < 0) {
            printf("Failed to create socket for %s\n", ip_address);
            continue;
        }

        if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            // Failed to connect, device is not available
            close(socket_fd);
            continue;
        }

        total_found++;

        char name[1024];
        memset(name, 0, sizeof(name));
        if (getnameinfo((struct sockaddr *)&address, sizeof(address), name, sizeof(name), NULL, 0, 0) == 0) {
            printf("Found wireless network device: %s (%s)\n", ip_address, name);
        } else {
            printf("Found wireless network device: %s\n", ip_address);
        }

        close(socket_fd);
    }

    printf("\nScanning completed. Found %d wireless network devices on subnet %s.*\n", total_found, subnet);

    return 0;
}