//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: innovative
/*
C Network Packet Monitoring Example Program
By: Your Name Here
Date: Today's date here

This program monitors network packets and displays information about them.
It can be used for network debugging and analysis purposes.

*/

#include <stdio.h>
#include <pcap.h>

int main(int argc, char **argv) {
    pcap_t *handle; /* Session handle */
    char errbuf[PCAP_ERRBUF_SIZE]; /* Error string */
    struct bpf_program fp; /* The compiled filter */
    char filter_exp[] = "ip"; /* The filter expression */
    bpf_u_int32 net; /* The IP of our sniffing device */
    struct pcap_pkthdr header; /* The packet header */
    const u_char *packet; /* The actual packet */

    /* Define the device */
    char *dev = "en0";
    /* If no device specified, use default */
    if (argc == 2) {
        dev = argv[1];
    }
    /* Get the IP of our sniffing device */
    if (pcap_lookupnet(dev, &net, NULL, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
    }
    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }
    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    /* Let's sniff and print packets */
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            /* EOF */
            continue;
        }
        printf("Packet length: %d\n", header.len);
    }
    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}