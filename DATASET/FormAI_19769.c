//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: peaceful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Print packet timestamp and length
    printf("%ld:%ld (GMT) packet length:%d\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

    // Print the packet data
    for (int i = 0; i < header->len; i++) {
        printf("%.2x ", *(pkt_data+i));
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the network device for packet capture
    pcap_t *handle = pcap_open_live(argv[1], 65535, 1, 1000, errbuf);

    if (!handle) {
        fprintf(stderr, "Could not open device %s: %s\n", argv[1], errbuf);
        return EXIT_FAILURE;
    }

    // Set the filter
    struct bpf_program fp;
    char filter_exp[] = "icmp or udp or tcp";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Could not compile filter\n");
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter\n");
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", argv[1]);

    // Capture packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the packet capture handle
    pcap_close(handle);

    return EXIT_SUCCESS;
}