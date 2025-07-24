//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: protected
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define SIZE_ETHERNET 14

void handler(u_char *user, const struct pcap_pkthdr *pkt_hdr, const u_char *pkt_data)
{
    const struct ether_header* ether_hdr;
    const struct iphdr* ip_hdr;
    const struct tcphdr* tcp_hdr;
    const struct udphdr* udp_hdr;
    const u_char* payload;
    int size_ip;
    int size_transport;
    int size_payload;

    // Parse Ethernet header
    ether_hdr = (struct ether_header*)(pkt_data);
    if(ntohs(ether_hdr->ether_type) != ETHERTYPE_IP)
    {
        printf("Not an IP packet.\n");
        return;
    }

    // Parse IP header
    ip_hdr = (struct iphdr*)(pkt_data + SIZE_ETHERNET);
    size_ip = ip_hdr->ihl * 4;
    if(size_ip < 20)
    {
        printf("Invalid IP header length: %u bytes\n", size_ip);
        return;
    }

    // Determine transport protocol
    switch(ip_hdr->protocol)
    {
        case IPPROTO_TCP:
            // Parse TCP header
            tcp_hdr = (struct tcphdr*)(pkt_data + SIZE_ETHERNET + size_ip);
            size_transport = tcp_hdr->doff * 4;
            if(size_transport < 20)
            {
                printf("Invalid TCP header length: %u bytes\n", size_transport);
                return;
            }

            // Parse payload
            payload = (u_char *)(pkt_data + SIZE_ETHERNET + size_ip + size_transport);
            size_payload = ntohs(ip_hdr->tot_len) - (size_ip + size_transport);

            printf("TCP Packet:\n");
            printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr*)&ip_hdr->saddr));
            printf("\tDestination IP: %s\n", inet_ntoa(*(struct in_addr*)&ip_hdr->daddr));
            printf("\tSource Port: %d\n", ntohs(tcp_hdr->source));
            printf("\tDestination Port: %d\n", ntohs(tcp_hdr->dest));
            printf("\tPayload (%d bytes):\n", size_payload);
            // Print payload in ASCII
            if(size_payload > 0)
            {
                int i;
                for(i = 0; i < size_payload; i++)
                {
                    printf("%c", isprint(payload[i]) ? payload[i] : '.');
                }
                printf("\n");
            }
            break;

        case IPPROTO_UDP:
            // Parse UDP header
            udp_hdr = (struct udphdr*)(pkt_data + SIZE_ETHERNET + size_ip);
            size_transport = ntohs(udp_hdr->len);

            // Parse payload
            payload = (u_char *)(pkt_data + SIZE_ETHERNET + size_ip + sizeof(struct udphdr));
            size_payload = ntohs(ip_hdr->tot_len) - (size_ip + sizeof(struct udphdr));

            printf("UDP Packet:\n");
            printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr*)&ip_hdr->saddr));
            printf("\tDestination IP: %s\n", inet_ntoa(*(struct in_addr*)&ip_hdr->daddr));
            printf("\tSource Port: %d\n", ntohs(udp_hdr->source));
            printf("\tDestination Port: %d\n", ntohs(udp_hdr->dest));
            printf("\tPayload (%d bytes):\n", size_payload);
            // Print payload in ASCII
            if(size_payload > 0)
            {
                int i;
                for(i = 0; i < size_payload; i++)
                {
                    printf("%c", isprint(payload[i]) ? payload[i] : '.');
                }
                printf("\n");
            }
            break;

        default:
            printf("Unknown transport protocol: %d\n", ip_hdr->protocol);
            break;
    }
}

int main(int argc, char** argv)
{
    char* device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    const u_char* packet;
    struct pcap_pkthdr packet_header;
    int packet_count_limit = -1;
    int timeout_limit = 10000; // 10 seconds

    if(argc > 1)
    {
        // Use specified device
        device = argv[1];
    }
    else
    {
        // Find a suitable device automatically
        device = pcap_lookupdev(errbuf);
        if(device == NULL)
        {
            printf("Error finding device: %s\n", errbuf);
            return 1;
        }
    }

    printf("Using device: %s\n", device);

    // Open a capture handle
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, errbuf);
    if(handle == NULL)
    {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    // Set the capture filter
    struct bpf_program filter;
    if(pcap_compile(handle, &filter, "ip", 1, 0) == -1)
    {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if(pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error installing filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start the capture loop
    pcap_loop(handle, packet_count_limit, handler, NULL);

    // Close the capture handle
    pcap_close(handle);

    return 0;
}