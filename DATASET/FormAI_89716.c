//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Romeo and Juliet
/* Romeo and Juliet style C Network Packet Monitoring program */

// Act 1: Initialization
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Declare variables
    pcap_t *handle;                     // Session handle
    char *dev = NULL;                   // Device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];      // Error string
    struct bpf_program filter;          // The compiled filter
    char filter_exp[] = "tcp";          // The filter expression
    bpf_u_int32 mask;                   // Netmask of the sniffing device
    bpf_u_int32 net;                    // IP of the sniffing device
    struct pcap_pkthdr header;          // The packet header
    const u_char *packet;               // The actual packet

    // Act 2: Setting up
    // Look up device to sniff on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    // Get device netmask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    // Open device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }
    // Compile the filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    // Apply the filter expression
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Act 3: Sniffing packets
    printf("Romeo: O brawling love, O loving hate!\n");
    printf("Juliet: Out, damned packet! out I say!\n");

    packet = pcap_next(handle, &header);
    while (packet != NULL) {
        printf("Romeo: See, how she leans her cheek upon her hand!\n");
        packet = pcap_next(handle, &header);
    }

    // Act 4: Cleaning up
    printf("Juliet: Good night, good night! parting is such sweet sorrow,\n");
    printf("Romeo: That I shall say good night till it be morrow.\n");

    pcap_freecode(&filter);
    pcap_close(handle);

    return EXIT_SUCCESS;
}