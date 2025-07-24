//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sock;
    char *iface = "eth0";
    unsigned char buf[2048];
    struct sockaddr_in source,dest;
    socklen_t saddr_size;
    int data_size;

    // Create raw socket
    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) {
        perror("socket error");
        exit(1);
    }

    // Bind socket to interface
    setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, iface, strlen(iface)+1);

    // Receive packet
    while (1) {
        saddr_size = sizeof(source);
        data_size = recvfrom(sock, buf, 2048, 0, (struct sockaddr *)&source, &saddr_size);

        if (data_size < 0) {
            perror("recvfrom error");
            close(sock);
            exit(1);
        }

        // Print packet information
        printf("Packet received from %s:\n", inet_ntoa(source.sin_addr));
        printf("Destination MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
        printf("Source MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", buf[6], buf[7], buf[8], buf[9], buf[10], buf[11]);
        printf("Ethernet type: %d\n", ntohs(*((unsigned short *)(buf + 12))));
        printf("Packet data:\n");
        for (int i = 0; i < data_size; i++) {
            printf("%.2X ", buf[i]);
            if ((i+1) % 16 == 0)
                printf("\n");
        }
        printf("\n\n");
    }

    close(sock);
    return 0;
}