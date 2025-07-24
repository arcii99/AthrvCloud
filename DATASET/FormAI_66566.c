//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_PACKET_SIZE 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Extract the Ethernet header
    struct ether_header* ethernet_header = (struct ether_header*) packet;

    // Make sure the packet is IP
    if (ntohs(ethernet_header->ether_type) != ETHERTYPE_IP) {
        return;
    }

    // Extract the IP header
    struct ip* ip_header = (struct ip*)(packet + sizeof(struct ether_header));

    // Make sure the packet is TCP
    if (ip_header->ip_p != IPPROTO_TCP) {
        return;
    }

    // Extract the TCP header
    struct tcphdr* tcp_header = (struct tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));

    // Print the source and destination IP and port
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Source Port: %d\n", ntohs(tcp_header->th_sport));
    printf("Destination Port: %d\n\n", ntohs(tcp_header->th_dport));
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Find the default network interface
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Unable to find default network device: %s\n", errbuf);
        exit(1);
    }

    // Open the network interface in promiscuous mode
    handle = pcap_open_live(dev, MAX_PACKET_SIZE, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    // Filter packets for TCP
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Unable to compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Unable to set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}