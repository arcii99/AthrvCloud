//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Alan Touring
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    printf("Packet length: %d\n", header->len);
}

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get the default network interface
    char *dev = pcap_lookupdev(error_buffer);
    if (dev == NULL) {
        printf("Could not find a default network interface: %s\n", error_buffer);
        return 1;
    }

    // Get the network interface's IP address and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, error_buffer) == -1) {
        printf("Could not get network address and mask for device %s: %s\n", dev, error_buffer);
        net = 0;
        mask = 0;
    }

    // Open the network interface for capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Could not open network interface %s: %s\n", dev, error_buffer);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &filter, "ip", 0, net) == -1) {
        printf("Could not compile filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply the filter expression
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Could not apply filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    pcap_loop(handle, 0, process_packet, NULL);

    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}