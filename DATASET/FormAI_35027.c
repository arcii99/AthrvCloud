//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 65536

void printHexArray(unsigned char *buffer, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

void printEthernetHeader(struct ethhdr *eth_header) {
    printf("========= Ethernet Header =========\n");
    printf("Destination MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", eth_header->h_dest[0], eth_header->h_dest[1], eth_header->h_dest[2], eth_header->h_dest[3], eth_header->h_dest[4], eth_header->h_dest[5]);
    printf("Source MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", eth_header->h_source[0], eth_header->h_source[1], eth_header->h_source[2], eth_header->h_source[3], eth_header->h_source[4], eth_header->h_source[5]);
    printf("Protocol: %d\n", ntohs(eth_header->h_proto));
}

void handlePacket(unsigned char *buffer, int size) {
    struct ethhdr *ethernet_header = (struct ethhdr *)buffer;
    printEthernetHeader(ethernet_header);
    printf("Packet Size: %d\n", size);
    printHexArray(buffer, size);
}

void handlePackets(int socket) {
    unsigned char buffer[BUFFER_SIZE];
    int size;
    while (1) {
        size = recvfrom(socket, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (size == -1) {
            perror("Error Reading Packets");
            exit(EXIT_FAILURE);
        }
        handlePacket(buffer, size);
    }
}

void startMonitoring(char *interface) {
    int socketDescriptor = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (socketDescriptor == -1) {
        perror("Error Creating Socket Descriptor. Try running as root");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_ll sockaddr;
    sockaddr.sll_family = AF_PACKET;
    sockaddr.sll_protocol = htons(ETH_P_ALL);
    sockaddr.sll_ifindex = if_nametoindex(interface);
    if (sockaddr.sll_ifindex == 0) {
        perror("Error Getting Interface Index");
        exit(EXIT_FAILURE);
    }

    if (bind(socketDescriptor, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
        perror("Error Binding Socket");
        exit(EXIT_FAILURE);
    }

    printf("Monitoring Packets on Interface: %s\n", interface);

    handlePackets(socketDescriptor);

    close(socketDescriptor);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    startMonitoring(argv[1]);
    return 0;
}