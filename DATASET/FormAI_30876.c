//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: expert-level
#include <pcap.h>  // include pcap library for packet capture
#include <stdio.h> // include standard input and output library
#include <arpa/inet.h> // include in_addr structure for IP address manipulation


#define ETHER_ADDR_LEN 6 // Define the length of MAC address

/* Ethernet header */
struct ether_header {
    u_char ether_dhost[ETHER_ADDR_LEN]; /* destination host address */
    u_char ether_shost[ETHER_ADDR_LEN]; /* source host address */
    u_short ether_type; /* IP? ARP? RARP? etc */
};

/* IP header */
struct ip_header {
    u_char ihl:4; /* header length */
    u_char version:4; /* version */
    u_char tos; /* type of service */
    u_short tlen; /* total length */
    u_short identification; /* identification */
    u_short flags_fo; /* flags and fragment offset field */
    u_char ttl; /* time to live */
    u_char protocol; /* protocol */
    u_short crc; /* checksum */
    struct in_addr saddr; /* source address */
    struct in_addr daddr; /* destination address */
};

/* TCP header */
struct tcp_header {
    u_short sport; /* source port */
    u_short dport; /* destination port */
    u_int seq; /* sequence number */
    u_int ack; /* acknowledgement number */
    u_char reserved:4; /* reserved */
    u_char offset:4; /* offset */
    u_char flags; /* flags */
    u_short window; /* window */
    u_short crc; /* checksum */
    u_short urgent_pointer; /* urgent pointer */
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    struct ether_header *eth_header;
    eth_header = (struct ether_header *) packet; // extract the ethernet header

    // If the packet is IP
    if (ntohs(eth_header->ether_type) == 0x0800) 
    {
        struct ip_header *ip_header;
        ip_header = (struct ip_header *) (packet + sizeof(struct ether_header)); // extract the IP header

        // If the protocol is TCP
        if (ip_header->protocol == IPPROTO_TCP) 
        {
            struct tcp_header *tcp_header;
            tcp_header = (struct tcp_header *) (packet + sizeof(struct ether_header) + sizeof(struct ip_header)); // extract the TCP header

            printf("Source IP: %s\n", inet_ntoa(ip_header->saddr));
            printf("Destination IP: %s\n", inet_ntoa(ip_header->daddr));
            printf("Source Port: %d\n", ntohs(tcp_header->sport));
            printf("Destination Port: %d\n", ntohs(tcp_header->dport));
            printf("-----------------------------------------------------\n");
        }
    }
}

int main()
{
    pcap_t *handle; // Handle for packet capture
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    struct bpf_program filter; // Filter to be applied for packet capture
    char *filter_exp = "tcp"; // Filter expression to capture only TCP packets
    bpf_u_int32 subnet_mask, ip; // Subnet mask and IP address of the device where packet capture is being done

    // Get the IP and subnet mask of the default network device
    if (pcap_lookupnet(pcap_lookupdev(error_buffer), &ip, &subnet_mask, error_buffer) == -1) 
    {
        printf("Error getting device info: %s\n", error_buffer);
        return 1;
    }

    // Open the network device for packet capture
    handle = pcap_open_live(pcap_lookupdev(error_buffer), BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) 
    {
        printf("Error opening device for capture: %s\n", error_buffer);
        return 1;
    }

    // Compile and apply the filter expression for packet capture
    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) 
    {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) 
    {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Packet capture started....\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup before exit
    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}