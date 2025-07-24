//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65536
#define MIN_UDP_LEN 8
#define TIMEOUT 5

int main()
{
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (sock < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
    {
        perror("Error setting socket option");
        exit(1);
    }

    char buffer[MAX_PACKET_SIZE];
    int read_size = 0;

    while (1)
    {
        struct sockaddr_in addr;
        unsigned int addr_length = sizeof(addr);
        read_size = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&addr, &addr_length);

        if (read_size < MIN_UDP_LEN)
        {
            continue;
        }

        struct udphdr *udp_header = (struct udphdr *)(buffer + sizeof(struct iphdr) + sizeof(struct ethhdr));

        if (ntohs(udp_header->dest) != 53)
        {
            continue;
        }

        printf("Signal strength: %d\n", (int)(buffer[22] - 256));

        memset(buffer, 0, MAX_PACKET_SIZE);
    }

    close(sock);
    return 0;
}