//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sock, port;
    char ip[16];
    struct sockaddr_in server;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the starting Port: ");
    scanf("%d", &port);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        perror("Socket error");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);

    for (int i = port; i <= 65535; i++)
    {
        server.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0)
        {
            printf("Port %d is open.\n", i);
        }
    }

    printf("Port scan complete.\n");

    return 0;
}