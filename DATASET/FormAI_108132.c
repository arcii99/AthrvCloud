//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ipAddress = argv[1];

    printf("Scanning ports on %s...\n", ipAddress);

    int socket_desc;
    struct sockaddr_in server;
    for (int port = 1; port <= 65535; port++) {
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            printf("Error creating socket\n");
            return 1;
        }

        server.sin_addr.s_addr = inet_addr(ipAddress);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
            close(socket_desc);
            continue;
        } else {
            printf("Port %d is open\n", port);
            close(socket_desc);
        }
    }

    printf("Port scan complete.\n");

    return 0;
}