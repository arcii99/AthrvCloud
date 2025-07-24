//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: minimalist
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_buffer) {
    // Code for handling packets goes here
}

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    // Get the network device to capture packets
    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    printf("Device: %s\n", dev);

    // Open the device for packet capture
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 0, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Loop through the packets and call the packet_handler function for each packet
    if (pcap_loop(handle, -1, packet_handler, NULL) < 0) {
        printf("pcap_loop() failed: %s\n", pcap_geterr(handle));
        return(1);
    }

    // Close the capture handle
    pcap_close(handle);

    return(0);
}