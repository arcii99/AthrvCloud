//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Ken Thompson
/* Ken Thompson style C network packet monitoring program */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>

int main() {

    // Open a raw socket to monitor network traffic
    int sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Buffer to store incoming network data
    unsigned char buffer[65536];

    while (1) {
        // Receive packets and store them in the buffer
        ssize_t num_bytes_received = recvfrom(sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (num_bytes_received == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Extract the Ethernet header from the packet
        struct ether_header *eth_header = (struct ether_header*) buffer;

        // Extract the source and destination MAC addresses from the Ethernet header
        unsigned char *src_mac = eth_header->ether_shost;
        unsigned char *dst_mac = eth_header->ether_dhost;

        // Print the source and destination MAC addresses to the console
        printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", src_mac[0], src_mac[1], src_mac[2], src_mac[3], src_mac[4], src_mac[5]);
        printf("Destination MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", dst_mac[0], dst_mac[1], dst_mac[2], dst_mac[3], dst_mac[4], dst_mac[5]);
        printf("-------------------------------------------------\n");
    }

    // Close the socket
    close(sock_fd);

    return 0;
}