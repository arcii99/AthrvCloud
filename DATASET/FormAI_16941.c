//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: light-weight
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void handle_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    static int count = 1;

    printf("\nPacket #%d:\n", count);

    // Ethernet header
    struct ether_header* eth_header = (struct ether_header*)packet;
    printf("- Source MAC address: %s\n", ether_ntoa((struct ether_addr*)eth_header->ether_shost));
    printf("- Destination MAC address: %s\n", ether_ntoa((struct ether_addr*)eth_header->ether_dhost));

    // IP header
    struct ip* ip_hdr = (struct ip*)(packet + sizeof(struct ether_header));
    printf("- Source IP address: %s\n", inet_ntoa(ip_hdr->ip_src));
    printf("- Destination IP address: %s\n", inet_ntoa(ip_hdr->ip_dst));

    // TCP header
    struct tcphdr* tcp_hdr = (struct tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));
    printf("- Source port: %d\n", ntohs(tcp_hdr->source));
    printf("- Destination port: %d\n", ntohs(tcp_hdr->dest));

    // Data
    const u_char* payload = packet + sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct tcphdr);
    int payload_size = ntohs(ip_hdr->ip_len) - sizeof(struct ip) - sizeof(struct tcphdr);
    if (payload_size > 0) {
        printf("- Data payload (%d bytes):\n", payload_size);
        for (int i = 0; i < payload_size; i++) {
            printf("%02x ", payload[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }

    count++;
}

int main(int argc, char** argv) {
    char* dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;

    // Find the default network interface
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open the network interface for packet capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Set the packet filter to capture only TCP/IP packets
    struct bpf_program fp;
    char filter_exp[] = "tcp and ip";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Start capturing packets
    pcap_loop(handle, -1, handle_packet, NULL);

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return EXIT_SUCCESS;
}