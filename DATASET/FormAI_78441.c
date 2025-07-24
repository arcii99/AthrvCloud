//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

#define ETHER_ADDR_LEN 6

// Ethernet header
typedef struct {
    u_char ether_dhost[ETHER_ADDR_LEN]; // destination host address
    u_char ether_shost[ETHER_ADDR_LEN]; // source host address
    u_short ether_type; // IP? ARP? RARP? etc
} ether_header;

// IP header
typedef struct {
    u_char ihl:4;
    u_char version:4;
    u_char tos;
    u_short tot_len;
    u_short id;
    u_short frag_off;
    u_char ttl;
    u_char protocol;
    u_short checksum;
    struct in_addr src_ip;
    struct in_addr dst_ip;
} ip_header;

// TCP header
typedef struct {
    u_short src_port;
    u_short dst_port;
    u_int seq_num;
    u_int ack_num;
    u_char data_offset:4;
    u_char reserved:4;
    u_char flags;
    u_short window;
    u_short checksum;
    u_short urgent_ptr;
} tcp_header;

// Print Ethernet header
void print_ethernet(const u_char *packet) {
    ether_header *eth = (ether_header*) packet;
    printf("Ethernet Header:\n");
    printf("\tDestination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2], eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);
    printf("\tSource MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2], eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);
    printf("\tType: %u\n", eth->ether_type);
}

// Print IP header
void print_ip(const u_char *packet) {
    ip_header *ip = (ip_header*) (packet + sizeof(ether_header));
    printf("IP Header:\n");
    printf("\tSource IP: %s\n", inet_ntoa(ip->src_ip));
    printf("\tDestination IP: %s\n", inet_ntoa(ip->dst_ip));
}

// Print TCP header
void print_tcp(const u_char *packet) {
    tcp_header *tcp = (tcp_header*) (packet + sizeof(ether_header) + sizeof(ip_header));
    printf("TCP Header:\n");
    printf("\tSource Port: %u\n", tcp->src_port);
    printf("\tDestination Port: %u\n", tcp->dst_port);
}

// Handle packet function
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int *count = (int*)args;
    printf("\nPacket Number: %d\n", ++(*count));
    print_ethernet(packet);
    print_ip(packet);
    print_tcp(packet);
}

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net, mask;
    int num_packets = 10, count = 0;

    // Get default device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    printf("Device: %s\n", dev);

    // Get network number and mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Sniff packets
    pcap_loop(handle, num_packets, handle_packet, (u_char*)&count);

    // Close handle
    pcap_close(handle);

    printf("\nNumber of Packets Sniffed: %d\n", count);

    return EXIT_SUCCESS;
}