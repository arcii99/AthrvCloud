//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <stdio.h>
#include <pcap.h>

void packet_handler(unsigned char *user, const struct pcap_pkthdr *header, const unsigned char *packet)
{
    printf("Received packet of length: %d\n", header->len);
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp and port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Open the capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Error looking up netmask for device: %s\n", errbuf);
        return 1;
    }
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
    {
        fprintf(stderr, "Error compiling packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Error setting packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    return 0;
}