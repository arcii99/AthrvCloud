//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void capture_packets(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    /* Recursive function to capture packets until user manually stops */
    printf("Packet captured\n");
    pcap_t *handle = (pcap_t *)args;
    pcap_sendpacket(handle, packet, header->caplen); // Forward the captured packets
    pcap_loop(handle, -1, capture_packets, (u_char *)handle); // Continue capturing packets
}

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];

    // Find default device for capturing
    char *device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", error_buffer);
        return 1;
    }

    // Open device for capturing
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 0, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, error_buffer);
        return 1;
    }

    // Start capturing packets recursively
    pcap_loop(handle, -1, capture_packets, (u_char *)handle);

    // Close the handle when done
    pcap_close(handle);

    return 0;
}