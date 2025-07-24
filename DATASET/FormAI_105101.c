//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: accurate
#include <stdio.h>
#include <pcap/pcap.h>

// Function to print packet information
void packet_handler(
    u_char *args,
    const struct pcap_pkthdr *header,
    const u_char *packet
) {
    printf("Packet length: %d\n", header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the network interface for packet capturing
    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open network interface: %s\n", errbuf);
        return(2);
    }

    // Capture packets with a filter
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int ret = pcap_lookupnet("en0", &net, &mask, errbuf);

    if (ret == -1) {
        fprintf(stderr, "Couldn't get netmask for device: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter: %s\n", pcap_geterr(handle));
        return(2);
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't set filter: %s\n", pcap_geterr(handle));
        return(2);
    }

    // Capture packets and call packet_handler for each one
    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}