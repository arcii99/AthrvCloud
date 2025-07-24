//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { // If argument count is not 2, print error and exit
        printf("Usage: %s <IP Address>\n", argv[0]);
        return -1;
    }

    int sock, port;
    struct sockaddr_in server;
    char *ip = argv[1];

    for (port=1; port <= 65535; port++) { // Scan all ports from 1 to 65535
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) { // If socket creation fails, print error and exit
            printf("Socket creation failed\n");
            return -1;
        }
        
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) { // If connection is successful, port is open
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    return 0;
}