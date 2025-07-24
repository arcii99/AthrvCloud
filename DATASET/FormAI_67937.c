//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main()
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask, net;

    // Get first available device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }

    // Open device for sniffing
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        printf("Error getting network info: %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1)
    {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply filter
    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, 0, process_packet, NULL);

    pcap_close(handle);
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    printf("Packet captured: %d bytes\n", header->len);
}