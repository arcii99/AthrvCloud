//FormAI DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TIMEOUT 3

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    int port;
    struct sockaddr_in server_addr;
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket()");
        return 1;
    }

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("The game is afoot!\n");

    for (port = 1; port <= 65535; port++)
    {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        {
            printf("Port %d is open! The game is afoot, Watson!\n", port);
        }
    }

    printf("The game is over!\n");

    return 0;
}