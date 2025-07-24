//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>      // Import pcap library 
#include <netinet/in.h>
#include <arpa/inet.h>

void got_packet(u_char *args, const struct pcap_pkthdr *pkt, const u_char *packet) {
    printf("Packet captured:\n");
    for (int i=0; i<pkt->len; i++) {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Get the device name to capture packets from
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open the device for live capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile and set the filter for capturing only TCP packets
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "tcp", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter 'tcp': %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter 'tcp': %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Start capturing and call the got_packet function for each packet
    printf("Starting packet sniffing on %s...\n", dev);
    pcap_loop(handle, -1, got_packet, NULL);

    // Cleanup and exit
    pcap_freecode(&fp);
    pcap_close(handle);
    return EXIT_SUCCESS;
}