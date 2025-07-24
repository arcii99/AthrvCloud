//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: ultraprecise
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/in.h> 
#include <netinet/ether.h>
#include <netinet/ip.h>

#define PROMISCOUS 1
#define BYTE_MASK 0xFF

void custom_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr header;
    const u_char *packet;
    int num_packets = 5; // Capture five packets

    // Check if a valid network interface was provided
    if (argc < 2) {
        printf("Please specify a network interface name\n");
        return 1;
    }

    // Open the network interface for packet capture
    handle = pcap_open_live(argv[1], BUFSIZ, PROMISCOUS, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    // Compile and apply the packet filter
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s\n", argv[1]);
        net = 0;
        mask = 0;
    }
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Capturing packets on device: %s\n", argv[1]);
    pcap_loop(handle, num_packets, custom_packet_handler, NULL);

    // Close the session
    pcap_close(handle);
    return 0;
}

void custom_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    eth_header = (struct ether_header *) packet;
    
    // Check if the frame contains an IP packet
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        const u_char *ip_packet;
        struct iphdr *ip_header;
        int ip_header_length;

        // Get the IP header and extract the protocol number
        ip_packet = packet + sizeof(struct ether_header);
        ip_header = (struct iphdr*) ip_packet;
        ip_header_length = ip_header->ihl * 4;
        
        printf("Packet captured\n");
        printf("Source MAC address: %s\n", ether_ntoa((struct ether_addr *) eth_header->ether_shost));
        printf("Destination MAC address: %s\n", ether_ntoa((struct ether_addr *) eth_header->ether_dhost));
        printf("Source IP address: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
        printf("Destination IP address: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->daddr));
        printf("Protocol: %d\n", ip_header->protocol);
        printf("Data:\n");
        
        // Print the payload data in hex format
        int i;
        for (i = ip_header_length; i < ntohs(ip_header->tot_len); i++) {
            printf("%02X ", packet[i] & BYTE_MASK);
            if ((i - ip_header_length + 1) % 16 == 0) {
                printf("\n");
            }
        }
    }
}