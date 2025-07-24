//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *device;
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Error finding device: %s\n", error_buffer);
        return 1;
    }

    if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1) {
        fprintf(stderr, "Error getting information for device: %s\n", device);
        return 1;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", error_buffer);
        return 1;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "Cannot compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Cannot set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethhdr *ethernet_header;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;

    ethernet_header = (struct ethhdr *) packet;
    if (ntohs(ethernet_header->h_proto) != ETH_P_IP) {
        printf("Not an IP packet. Ignoring...\n");
        return;
    }

    ip_header = (struct iphdr *) (packet + sizeof(struct ethhdr));
    if (ip_header->protocol != IPPROTO_TCP) {
        printf("Not a TCP packet. Ignoring...\n");
        return;
    }

    tcp_header = (struct tcphdr *) (packet + sizeof(struct ethhdr) + sizeof(struct iphdr));
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->saddr));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->daddr));
    printf("Source Port: %d\n", ntohs(tcp_header->source));
    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
}