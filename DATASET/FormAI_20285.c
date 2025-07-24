//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define SNAPLEN 65535

void handle_packet(u_char *args, const struct pcap_pkthdr *hdr, const u_char *packet)
{
    struct ether_header *ethernet_header = (struct ether_header *)packet;
    struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ether_header));
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
    char source_mac[18], dest_mac[18], source_ip[INET_ADDRSTRLEN], dest_ip[INET_ADDRSTRLEN];
    int source_port, dest_port;

    /* extract source and destination MAC addresses */
    sprintf(source_mac, "%02x:%02x:%02x:%02x:%02x:%02x", ethernet_header->ether_shost[0],
            ethernet_header->ether_shost[1], ethernet_header->ether_shost[2], ethernet_header->ether_shost[3],
            ethernet_header->ether_shost[4], ethernet_header->ether_shost[5]);
    sprintf(dest_mac, "%02x:%02x:%02x:%02x:%02x:%02x", ethernet_header->ether_dhost[0],
            ethernet_header->ether_dhost[1], ethernet_header->ether_dhost[2], ethernet_header->ether_dhost[3],
            ethernet_header->ether_dhost[4], ethernet_header->ether_dhost[5]);

    /* extract source and destination IP addresses and port numbers */
    inet_ntop(AF_INET, &ip_header->saddr, source_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &ip_header->daddr, dest_ip, INET_ADDRSTRLEN);
    source_port = ntohs(tcp_header->source);
    dest_port = ntohs(tcp_header->dest);

    /* print out network information */
    printf("Source MAC: %s\n", source_mac);
    printf("Destination MAC: %s\n", dest_mac);
    printf("Source IP: %s, Source Port: %d\n", source_ip, source_port);
    printf("Destination IP: %s, Destination Port: %d\n", dest_ip, dest_port);
}

int main(int argc, char *argv[])
{
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 net, mask;
    struct bpf_program filter;

    /* get default network interface */
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    /* open network interface in promiscuous mode */
    handle = pcap_open_live(device, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    /* compile filter expression */
    if (pcap_compile(handle, &filter, "tcp", 0, mask) < 0) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* apply filter */
    if (pcap_setfilter(handle, &filter) < 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* capture packets */
    pcap_loop(handle, -1, handle_packet, NULL);
    pcap_close(handle);

    return EXIT_SUCCESS;
}