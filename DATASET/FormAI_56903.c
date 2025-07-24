//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<arpa/inet.h>
#include<netinet/ether.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main()
{
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;
    int num_packets = 10;

    // get the default values for subnet mask and IP address
    pcap_lookupnet("eth0", &ip, &subnet_mask, error_buffer);

    // open device for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, -1, error_buffer);
    if(handle == NULL)
    {
        printf("Could not open device!\n");
        return -1;
    }

    // set the filter for capturing only TCP packets on port 80
    if(pcap_compile(handle, &filter, filter_exp, 0, ip) == -1)
    {
        printf("Could not compile filter!\n");
        return -1;
    }

    if(pcap_setfilter(handle, &filter) == -1)
    {
        printf("Could not apply filter!\n");
        return -1;
    }

    // start capturing packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    const struct ether_header *ethernet_header;
    const struct ip *ip_header;
    const struct tcphdr *tcp_header;
    char source_mac[18], dest_mac[18];
    char source_ip[16], dest_ip[16];
    u_int source_port, dest_port;

    // get ethernet header details
    ethernet_header = (struct ether_header*) buffer;
    strcpy(source_mac, ether_ntoa((struct ether_addr*) ethernet_header->ether_shost));
    strcpy(dest_mac, ether_ntoa((struct ether_addr*) ethernet_header->ether_dhost));

    // get IP header details
    ip_header = (struct ip*) (buffer + sizeof(struct ether_header));
    strcpy(source_ip, inet_ntoa(ip_header->ip_src));
    strcpy(dest_ip, inet_ntoa(ip_header->ip_dst));

    // get TCP header details
    tcp_header = (struct tcphdr*) (buffer + sizeof(struct ether_header) + sizeof(struct ip));
    source_port = ntohs(tcp_header->source);
    dest_port = ntohs(tcp_header->dest);

    // print the packet details
    printf("Packet captured:\n");
    printf("Source MAC: %s\n", source_mac);
    printf("Destination MAC: %s\n", dest_mac);
    printf("Source IP: %s\n", source_ip);
    printf("Destination IP: %s\n", dest_ip);
    printf("Source port: %d\n", source_port);
    printf("Destination port: %d\n", dest_port);
}