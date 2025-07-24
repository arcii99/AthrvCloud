//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char *argv[]) {

    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Find the default device if not specified
    if (argc < 2) {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return 1;
        }
    } else {
        dev = argv[1];
    }

    // Open the capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Capture packets
    printf("Starting capture on device %s...\n", dev);
    pcap_loop(handle, 0, process_packet, NULL);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {

    // Print packet length
    printf("Packet length: %d\n", header->len);

    // Print packet data
    for (int i=0; i<header->len; i++) {
        printf("%02x ", buffer[i]);
        if ((i+1)%16==0 && i!=0) {
            printf("\n");
        }
    }

    printf("\n\n");
}