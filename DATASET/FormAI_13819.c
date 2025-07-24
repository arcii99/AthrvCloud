//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet captured! Length: %d\n", header->len);
    // do something with the captured packet data here
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr header;
    const u_char *packet;

    printf("Starting packet monitoring program...\n");

    // find the default network interface
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Failed to find default interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // get the network address and netmask from the default interface
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Failed to get network address and netmask for %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open the network interface in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Failed to open interface %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // compile and set the packet filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Failed to compile packet filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Failed to set packet filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // start capturing packets
    printf("Capturing packets on %s...\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Packet monitoring program complete.\n");

    return EXIT_SUCCESS;
}