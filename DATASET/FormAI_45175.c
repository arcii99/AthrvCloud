//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: energetic
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured, size: %d\n", header->len);
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open network interface for listening
    pcap_t *pcap_handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);

    if (pcap_handle == NULL)
    {
        fprintf(stderr, "Could not open network interface: %s\n", errbuf);
        return -1;
    }

    // Compile filter expression using pcap_compile()
    struct bpf_program filter;

    if (pcap_compile(pcap_handle, &filter, "udp dst port 53", 1, PCAP_NETMASK_UNKNOWN) == -1)
    {
        fprintf(stderr, "Could not compile filter: %s\n", pcap_geterr(pcap_handle));
        return -1;
    }

    // Set filter using pcap_setfilter()
    if (pcap_setfilter(pcap_handle, &filter) == -1)
    {
        fprintf(stderr, "Could not set filter: %s\n", pcap_geterr(pcap_handle));
        return -1;
    }

    // Start capturing packets
    printf("Starting packet capture...\n");
    pcap_loop(pcap_handle, 0, packet_handler, NULL);

    // Stop capturing packets
    pcap_close(pcap_handle);
    printf("Packet capture complete.\n");

    return 0;
}