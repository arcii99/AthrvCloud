//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
// C program for capturing packets using pcap library

#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_data) {
    printf("\nPacket received. Packet size: %d bytes\n", packet_header->len);

    // Print details
    struct ether_header* ethernet_header = NULL;
    ethernet_header = (struct ether_header*) packet_data;
    printf("\tSource MAC address: %s\n", ether_ntoa((struct ether_addr *) ethernet_header->ether_shost));
    printf("\tDestination MAC address: %s\n", ether_ntoa((struct ether_addr *) ethernet_header->ether_dhost));
}

int main(int argc, char **argv) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 1;
    int timeout_limit = 10000; // in milliseconds

    // Get the network device to capture packets
    char *device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }
    printf("Device: %s\n", device);

    // Open device in promiscuous mode
    handle = pcap_open_live(device, BUFSIZ, packet_count_limit, timeout_limit, error_buffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return 1;
    }

    // Capture packets
    pcap_loop(handle, packet_count_limit, packet_handler, NULL);

    // Free the handle
    pcap_close(handle);

    return 0;
}