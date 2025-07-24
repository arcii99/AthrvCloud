//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    // Packet information.
    printf("Packet size: %d bytes\nTimestamp: %s", header->len, ctime(&header->ts.tv_sec));
}

int main(int argc,char **argv) {
    char *device; // Interface name.
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer.
    bpf_u_int32 mask; // Interface netmask.
    bpf_u_int32 net; // Interface IP address.
    pcap_t *pcap_handle; // Handle for the PCAP library.

    // Get the name of the first interface suitable for packet capture.
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Error finding suitable network device: %s\n", error_buffer);
        return 1;
    }

    // Get the network number and mask associated with the interface.
    if (pcap_lookupnet(device, &net, &mask, error_buffer) == -1) {
        printf("Error getting network number and mask for device %s: %s\n", device, error_buffer);
        net = 0;
        mask = 0;
    }

    // Open the network interface for packet capture.
    pcap_handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (pcap_handle == NULL) {
        printf("Error opening device %s for packet capture: %s\n", device, error_buffer);
        return 1;
    }

    // Start capturing packets.
    printf("Packet capturing on %s...\n", device);
    pcap_loop(pcap_handle, 0, packet_handler, NULL);

    // Close the packet capture session.
    pcap_close(pcap_handle);
    printf("Packet capture complete.\n");

    return 0;
}