//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header,
                    const u_char *packet);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;

    // Check for command line arguments
    if (argc != 2) {
        printf("Usage: %s <interface>", argv[0]);
        return 1;
    }

    // Get network number and mask associated with capture device
    if (pcap_lookupnet(argv[1], &ip, &subnet_mask, errbuf) == -1) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Open capture device
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *user, const struct pcap_pkthdr *header,
                    const u_char *packet) {
    // Process packet here
}