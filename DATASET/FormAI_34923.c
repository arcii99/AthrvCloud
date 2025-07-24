//FormAI DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    printf("Scanning ports...\n");

    for (int port = 1; port <= 65535; port++) {
        server_addr.sin_port = htons(port);

        if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", port);
        }
    }

    close(socket_fd);

    return 0;
}