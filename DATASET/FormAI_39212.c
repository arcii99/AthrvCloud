//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: detailed
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/in.h>

void packet_handler(const u_char *packet, const struct pcap_pkthdr *packet_header, const u_char *extra_info) {
    struct ether_header *eth_header = (struct ether_header*) packet;
    struct iphdr *ip_header = (struct iphdr*) (packet + sizeof(struct ether_header));
    struct udphdr *udp_header = (struct udphdr*) (packet + sizeof(struct ether_header) + sizeof(struct iphdr));
    struct tcphdr *tcp_header = (struct tcphdr*) (packet + sizeof(struct ether_header) + sizeof(struct iphdr));
    
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        char dest_ip[INET_ADDRSTRLEN], src_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ip_header->daddr), dest_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_header->saddr), src_ip, INET_ADDRSTRLEN);

        printf("IP Packet:\n");
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dest_ip);
        
        if (ip_header->protocol == IPPROTO_UDP) {
            printf("UDP Packet:\n");
            printf("Source Port: %d\n", ntohs(udp_header->source));
            printf("Destination Port: %d\n", ntohs(udp_header->dest));
        } 
        else if (ip_header->protocol == IPPROTO_TCP) {
            printf("TCP Packet:\n");
            printf("Source Port: %d\n", ntohs(tcp_header->source));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        }
        printf("\n");
    }
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr packet_header;
    struct bpf_program filter;
    char filter_exp[] = "udp or tcp";
    bpf_u_int32 subnet_mask, ip;

    if (pcap_lookupnet("wlan0", &ip, &subnet_mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", "wlan0", errbuf);
        subnet_mask = 0;
        ip = 0;
    }

    handle = pcap_open_live("wlan0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", "wlan0", errbuf);
        return -1;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) {
        printf("Couldn't compile filter expression: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return -1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return -1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}