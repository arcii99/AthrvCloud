//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet received, size: %d bytes\n", header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 netmask, subnet;

    // Open the network device for capturing
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (!handle) {
        fprintf(stderr, "Failed to open device: %s\n", errbuf);
        return 1;
    }

    // Get the network mask and subnet
    if (pcap_lookupnet("eth0", &subnet, &netmask, errbuf) == -1) {
        fprintf(stderr, "Failed to get network information: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, "icmp", 0, subnet) == -1) {
        fprintf(stderr, "Failed to compile filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to set filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    if (pcap_loop(handle, 0, packet_handler, NULL) == -1) {
        fprintf(stderr, "Failed to capture packets: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}