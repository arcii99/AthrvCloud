//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: safe
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Retrieve device name
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open device for capturing packets
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Set filter expression (optional)
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "port 80", 1, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "port 80", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "port 80", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets indefinitely
    printf("Starting packet capture on device: %s\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close capturing device
    pcap_close(handle);
    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Process captured packet here
    printf("Packet captured (length = %d)\n", header->len);
}