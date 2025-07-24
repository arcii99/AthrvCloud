//FormAI DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char* ip, int port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock_fd < 0)
    {
        perror("ERROR: Failed to create socket");
        return;
    }

    int result = connect(sock_fd, (struct sockaddr*)&addr, sizeof(addr));

    if (result < 0)
    {
        // Port is closed
        printf("Port %d: Closed\n", port);
    }
    else
    {
        // Port is open
        printf("Port %d: Open\n", port);
        close(sock_fd);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("USAGE: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* ip = argv[1];
    printf("Scanning ports for %s...\n", ip);

    for (int port = MIN_PORT; port <= MAX_PORT; ++port)
    {
        scan_port(ip, port);
    }

    printf("Port scan complete.\n");

    return 0;
}