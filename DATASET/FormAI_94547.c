//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pcap.h>
#include<net/ethernet.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/udp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;
    printf("\nPacket number %d:\n", count);
    printf("------------------------\n");

    // access the Ethernet header
    struct ethhdr *ethernet_header = (struct ethhdr*)packet;
    printf("\nEthernet Header\n");
    printf("------------------------\n");
    printf("Destination MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", ethernet_header->h_dest[0], ethernet_header->h_dest[1], ethernet_header->h_dest[2], ethernet_header->h_dest[3], ethernet_header->h_dest[4], ethernet_header->h_dest[5]);
    printf("Source MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", ethernet_header->h_source[0], ethernet_header->h_source[1], ethernet_header->h_source[2], ethernet_header->h_source[3], ethernet_header->h_source[4], ethernet_header->h_source[5]);
    printf("Protocol Type: %d\n", ethernet_header->h_proto);

    // access the IP header
    struct iphdr *ip_header = (struct iphdr*)(packet + sizeof(struct ethhdr));
    printf("\nIP Header\n");
    printf("------------------------\n");
    printf("Version: %d\n", ip_header->version);
    printf("Header Length: %d\n", ip_header->ihl * 4);
    printf("Type of Service: %d\n", ip_header->tos);
    printf("Total Length: %d\n", ntohs(ip_header->tot_len));
    printf("Identification: %d\n", ntohs(ip_header->id));
    printf("Fragment Offset: %d\n", ntohs(ip_header->frag_off));
    printf("Time to Live: %d\n", ip_header->ttl);
    printf("Protocol: %d\n", ip_header->protocol);
    printf("Header Checksum: %d\n", ntohs(ip_header->check));
    printf("Source IP Address: %s\n", inet_ntoa(*(struct in_addr*)&ip_header->saddr));
    printf("Destination IP Address: %s\n", inet_ntoa(*(struct in_addr*)&ip_header->daddr));

    // access the TCP header
    struct tcphdr *tcp_header = (struct tcphdr*)(packet + sizeof(struct ethhdr) + ip_header->ihl * 4);
    printf("\nTCP Header\n");
    printf("------------------------\n");
    printf("Source Port: %d\n", ntohs(tcp_header->source));
    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    printf("Sequence Number: %d\n", ntohl(tcp_header->seq));
    printf("Acknowledgment Number: %d\n", ntohl(tcp_header->ack_seq));
    printf("Header Length: %d\n", tcp_header->doff * 4);
    printf("URG Flag: %d\n", tcp_header->urg);
    printf("ACK Flag: %d\n", tcp_header->ack);
    printf("PSH Flag: %d\n", tcp_header->psh);
    printf("RST Flag: %d\n", tcp_header->rst);
    printf("SYN Flag: %d\n", tcp_header->syn);
    printf("FIN Flag: %d\n", tcp_header->fin);
    printf("Window Size: %d\n", ntohs(tcp_header->window));
    printf("Checksum: %d\n", ntohs(tcp_header->check));
    printf("Urgent Pointer: %d\n", ntohs(tcp_header->urg_ptr));

    count++;
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    // open a live capture handle
    pcap_t *packet_capture_handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
    if (packet_capture_handle == NULL)
    {
        printf("Error: Could not open capture handle\n");
        return 1;
    }

    // compile and apply the filter
    struct bpf_program filter;
    pcap_compile(packet_capture_handle, &filter, "tcp", 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(packet_capture_handle, &filter);

    // start capturing packets
    pcap_loop(packet_capture_handle, -1, packet_handler, NULL);

    // cleanup
   pcap_freecode(&filter);
   pcap_close(packet_capture_handle);

    return 0;
}