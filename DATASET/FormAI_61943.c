//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h>

void packet_capture(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *ethernet_header;
    int data_size;

    // Retrieve Ethernet header
    ethernet_header = (struct ether_header *) packet;

    // Retrieve packet data size
    data_size = header->len;

    // Print captured data
    printf("Packet captured: %d bytes\n", data_size);
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", ethernet_header->ether_shost[0], ethernet_header->ether_shost[1], ethernet_header->ether_shost[2], ethernet_header->ether_shost[3], ethernet_header->ether_shost[4], ethernet_header->ether_shost[5]);
    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", ethernet_header->ether_dhost[0], ethernet_header->ether_dhost[1], ethernet_header->ether_dhost[2], ethernet_header->ether_dhost[3], ethernet_header->ether_dhost[4], ethernet_header->ether_dhost[5]);
    
    // Check if packet is of TCP protocol
    if (ntohs(ethernet_header->ether_type) == ETHERTYPE_IP) {
        printf("Protocol: IP\n");
    } else if (ntohs(ethernet_header->ether_type) == ETHERTYPE_ARP) {
        printf("Protocol: ARP\n");
    } else if (ntohs(ethernet_header->ether_type) == ETHERTYPE_REVARP) {
        printf("Protocol: RARP\n");
    } else {
        printf("Protocol: Unknown\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    int num_packets = 10;

    // Open network device for capturing packets
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 2;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Set compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Begin packet capture loop
    printf("Packet capture started...\n");
    pcap_loop(handle, num_packets, packet_capture, NULL);

    // Close handle
    pcap_close(handle);

    return 0;
}