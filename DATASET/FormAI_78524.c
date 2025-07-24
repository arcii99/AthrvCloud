//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <pcap/pcap.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];    // Error buffer
    pcap_t *handle;                   // Session handle
    char *dev;                        // The device to sniff on
    bpf_u_int32 net;                  // The IP of our sniffing device
    bpf_u_int32 mask;                 // The subnet mask of our sniffing device
    struct bpf_program fp;            // The compiled filter expression

    // Determine the device to sniff on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get the network and subnet mask of the sniffing device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply the packet filter
    if (pcap_compile(handle, &fp, "tcp and dst port 80", 0, net) == -1)
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "tcp and dst port 80", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "tcp and dst port 80", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Begin sniffing loop
    pcap_loop(handle, -1, process_packet, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return EXIT_SUCCESS;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured of size %d\n", header->len);
}