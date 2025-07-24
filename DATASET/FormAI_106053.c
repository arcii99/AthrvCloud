//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pcap.h>

#define ETHER_ADDR_LEN 6
#define SIZE_ETHER_HEADER 14

/* Ethernet header */
typedef struct ethernet_header {
    u_char ether_dest_address[ETHER_ADDR_LEN];
    u_char ether_src_address[ETHER_ADDR_LEN];
    u_short ether_type;
} ethernet_header;

/* IP header */
typedef struct ip_header {
    u_char ip_version_and_header_length;
    u_char ip_tos;
    u_short ip_total_length;
    u_short ip_id;
    u_short ip_flags_and_offset;
    u_char ip_ttl;
    u_char ip_protocol;
    u_short ip_header_checksum;
    struct in_addr ip_source_address;
    struct in_addr ip_destination_address;
} ip_header;

/* TCP header */
typedef struct tcp_header {
    u_short tcp_source_port;
    u_short tcp_destination_port;
    u_int tcp_sequence_number;
    u_int tcp_acknowledgment_number;
    u_char tcp_offset_reserved;
    u_char tcp_flags;
    u_short tcp_window_size;
    u_short tcp_checksum;
    u_short tcp_urgent_pointer;
} tcp_header;

/* Callback function for pcap loop */
void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int packet_number = 1;
    ethernet_header *ethernet = (ethernet_header*)(packet);
    if(ntohs(ethernet->ether_type) == 0x0800) { /* IP packet */
        ip_header *ip = (ip_header*)(packet + SIZE_ETHER_HEADER);
        if(ip->ip_protocol == IPPROTO_TCP) { /* TCP packet */
            tcp_header *tcp = (tcp_header*)(packet + SIZE_ETHER_HEADER + sizeof(ip_header));
            printf("Packet number %d\n", packet_number++);
            printf("   Source IP address: %s\n", inet_ntoa(ip->ip_source_address));
            printf("   Destination IP address: %s\n", inet_ntoa(ip->ip_destination_address));
            printf("   Source port: %d\n", ntohs(tcp->tcp_source_port));
            printf("   Destination port: %d\n", ntohs(tcp->tcp_destination_port));
        }
    }
}

int main()
{
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handler;
    struct bpf_program filter;
    char filter_exp[] = "src host 192.168.1.150";

    /* Get device to use */
    device = pcap_lookupdev(error_buffer);
    if(device == NULL) {
        printf("Error finding default device: %s\n", error_buffer);
        return 1;
    }

    /* Open device */
    handler = pcap_open_live(device, BUFSIZ, 0, 1000, error_buffer);
    if(handler == NULL) {
        printf("Error opening device %s: %s\n", device, error_buffer);
        return 1;
    }

    /* Compile filter expression */
    if(pcap_compile(handler, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handler));
        return 1;
    }

    /* Apply filter expression */
    if(pcap_setfilter(handler, &filter) == -1) {
        printf("Error setting filter expression: %s\n", pcap_geterr(handler));
        return 1;
    }

    /* Capture packets */
    printf("Listening on %s...\n", device);
    pcap_loop(handler, -1, capture_packet, NULL);

    /* Cleanup */
    pcap_freecode(&filter); 
    pcap_close(handler); 

    return 0;
}