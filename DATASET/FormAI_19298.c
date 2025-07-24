//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *packet_header, const u_char *packet_body);

int main(int argc, char **argv)
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 net_ip;
    bpf_u_int32 net_mask;

    // Open the device for sniffing
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", error_buffer);
        return 1;
    }

    // Get the network address and mask
    if (pcap_lookupnet("eth0", &net_ip, &net_mask, error_buffer) == -1) {
        fprintf(stderr, "Could not get IP and mask for device: %s\n", error_buffer);
        net_ip = 0;
        net_mask = 0;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, net_mask) == -1) {
        fprintf(stderr, "Could not compile filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply the filter to the device
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Could not apply filter to device: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *packet_header, const u_char *packet_body)
{
    // Analyze the packet body here
    printf("Packet received!\n");
}