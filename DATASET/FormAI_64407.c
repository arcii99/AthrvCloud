//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surrealist
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    struct bpf_program filter;
    bpf_u_int32 netmask, subnet;

    // Open the network interface for live capturing
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    // Compile and set the filter for capturing TCP packets
    pcap_compile(pcap_handle, &filter, "tcp", 0, subnet);
    pcap_setfilter(pcap_handle, &filter);

    // Capture packets and handle them using the packet_handler function
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    // Close the pcap session
    pcap_close(pcap_handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured! Length: %d\n", header->len);
    // You can manipulate the packet data here
}