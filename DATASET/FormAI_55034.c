//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: rigorous
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void capture_packet(u_char* args, const struct pcap_pkthdr* header, 
    const u_char* packet) {
    struct ether_header* eth_header = (struct ether_header*) packet;
    if(ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
        return; // Ignore non-IP packets
    }

    // Extract IP header
    struct ip* ip_header = (struct ip*) (packet + sizeof(struct ether_header));
    if(ip_header->ip_p != IPPROTO_TCP) {
        return; // Ignore non-TCP packets
    }

    // Extract TCP header
    struct tcphdr* tcp_header = (struct tcphdr*) (packet + sizeof(struct ether_header) 
        + sizeof(struct ip));
    int tcp_header_len = tcp_header->th_off * 4;

    // Extract payload
    u_char* payload = (u_char*) (packet + sizeof(struct ether_header) 
        + sizeof(struct ip) + tcp_header_len);
    int payload_len = ntohs(ip_header->ip_len) - (sizeof(struct ip) 
        + tcp_header_len);

    // Print packet information
    printf("Packet captured- src: %s:%d, dst: %s:%d, length: %d\n",
        inet_ntoa(ip_header->ip_src), ntohs(tcp_header->th_sport), 
        inet_ntoa(ip_header->ip_dst), ntohs(tcp_header->th_dport), payload_len);

    // Print payload in hex format
    printf("Payload (hex): ");
    for(int i = 0; i < payload_len; i++) {
        printf("%02x ", payload[i]);
    }
    printf("\n\n");
}

int main() {
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80"; // Capture only HTTP traffic
    bpf_u_int32 net;

    // Find the network device to capture packets
    char* dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    printf("Device to capture packets: %s\n", dev);

    // Open the network device in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply the filter
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets indefinitely
    printf("Ready to capture packets...\n");
    pcap_loop(handle, -1, capture_packet, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return EXIT_SUCCESS;
}