//FormAI DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 1024

int main(int argc, char **argv) {
    int sock_fd, port_no;
    struct sockaddr_in target_addr;
    char *ip_addr;
    int open_ports[MAX_PORTS];

    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip_addr = argv[1];
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(ip_addr);

    printf("Scanning ports...\n");

    for (port_no = 1; port_no <= MAX_PORTS; port_no++) {
        target_addr.sin_port = htons(port_no);
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        if (connect(sock_fd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port_no);
            open_ports[port_no - 1] = port_no;
        } else {
            open_ports[port_no - 1] = 0;
        }
        close(sock_fd);
    }

    printf("Port scanning completed.\n\n");

    printf("Analysis report:\n");
    printf("-----------------\n");
    printf("Total number of ports scanned: %d\n", MAX_PORTS);

    int total_open_ports = 0;
    int port;
    for (port = 0; port < MAX_PORTS; port++) {
        if (open_ports[port]) {
            total_open_ports++;
        }
    }

    if (total_open_ports == 0) {
        printf("No open ports found on %s\n", ip_addr);
    } else {
        printf("Total number of open ports: %d\n", total_open_ports);
        printf("Open ports:\n");
        printf("-----------\n");
        for (port = 0; port < MAX_PORTS; port++) {
            if (open_ports[port]) {
                printf("%d\n", open_ports[port]);
            }
        }
    }

    exit(EXIT_SUCCESS);
}