//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 80
#define MAX_PACKET_SIZE 65536

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./scanner <IP address>\n");
        exit(1);
    }

    char *target = argv[1];

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == -1)
    {
        printf("Failed to create socket...\n");
        exit(1);
    }

    printf("Scanner Started...\n");

    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(PORT);
    target_addr.sin_addr.s_addr = inet_addr(target);

    printf("Scanning target IP address %s...\n", target);

    if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) != -1)
    {
        printf("Port %d is OPEN on %s\n", PORT, target);
    }
    else
    {
        printf("Port %d is CLOSED on %s\n", PORT, target);
    }

    printf("Scanner Finished...\n");

    close(sock);

    return 0;
}