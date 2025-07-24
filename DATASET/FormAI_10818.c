//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet received with length %d\n", header->len);
}

int main()
{
    pcap_t *handle; // Network interface handle
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    struct bpf_program fp; // Compiled filter expression
    char filter_exp[] = "port 80"; // Filter expression
    bpf_u_int32 subnet_mask, ip; // Subnet mask and IP address

    // Get network interface for capturing packets
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get IP and subnet mask for network interface
    if (pcap_lookupnet(dev, &ip, &subnet_mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        ip = 0;
        subnet_mask = 0;
    }

    // Open the network interface handle for packet capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply filter expression to packet capturing handle
    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Begin packet capturing loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the network interface handle
    pcap_close(handle);

    return EXIT_SUCCESS;
}