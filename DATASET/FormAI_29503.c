//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n");
    // add packet processing code here
}

int main()
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;
    int num_packets = 10; // number of packets to capture

    // find the first available network interface
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // get the network number and mask associated with the interface
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open the network interface for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // compile and apply the BPF filter
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "tcp port 80", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "tcp port 80", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // loop through packets and call handle_packet for each one
    pcap_loop(handle, num_packets, handle_packet, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}