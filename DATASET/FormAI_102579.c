//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <pcap.h>

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    struct ether_header *eth_header = (struct ether_header*) packet;

    printf("\n ----- Packet Captured ----- \n");

    printf("\nEthernet Header: \n");
    printf("\tSource MAC Address: %s", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
    printf("\tDestination MAC Address: %s", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));

    printf("\n");

    return;
}

int main() {

    char *network_interface = "wlan0";
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 net, mask;
    struct bpf_program filter;

    printf("\nStarting Network Packet Monitoring...\n");

    handle = pcap_open_live(network_interface, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error opening network interface: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    if (pcap_lookupnet(network_interface, &net, &mask, error_buffer) == -1) {
        fprintf(stderr, "Error getting network address and mask: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    printf("\nListening on: %s\n", network_interface);

    if (pcap_compile(handle, &filter, "ether proto 0x0800", 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    printf("\nFilter set to: ether proto 0x0800\n");

    pcap_loop(handle, -1, capture_packet, NULL);

    pcap_close(handle);
    printf("\nExiting Network Packet Monitoring...\n");

    return EXIT_SUCCESS;
}