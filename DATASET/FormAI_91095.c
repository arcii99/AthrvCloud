//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/ether.h>
#include <netinet/tcp.h>

/* This function will be called for every captured packet */
void capturePacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ether_header *ether_hdr;
    const struct ip *ip_hdr;
    const struct tcphdr *tcp_hdr;
    u_int16_t ether_type;

    /* Get the Ethernet header */
    ether_hdr = (const struct ether_header *) packet;
    /* Get the Ethernet type */
    ether_type = ntohs(ether_hdr->ether_type);

    /* If Ethernet type is IP */
    if (ether_type == ETHERTYPE_IP) {
        /* Get the IP header */
        ip_hdr = (const struct ip *) (packet + sizeof(struct ether_header));
        /* If protocol is TCP */
        if (ip_hdr->ip_p == IPPROTO_TCP) {
            /* Get the TCP header */
            tcp_hdr = (const struct tcphdr *) (packet + sizeof(struct ether_header) + (ip_hdr->ip_hl * 4));
            /* Print the packet details */
            printf("Inbound TCP packet: %s:%d -> %s:%d\n",
                    inet_ntoa(ip_hdr->ip_src), ntohs(tcp_hdr->th_sport),
                    inet_ntoa(ip_hdr->ip_dst), ntohs(tcp_hdr->th_dport));
        }
    }
}

int main(int argc, char **argv) {
    char *interface = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count;

    /* Check if the user provided an interface name */
    if (argc == 2) {
        interface = argv[1];
    } else {
        printf("Please provide an interface name.\n");
        return 1;
    }

    /* Open the device for packet capture */
    handle = pcap_open_live(interface, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", interface, error_buffer);
        return 2;
    }

    /* Start packet capture */
    packet_count = pcap_loop(handle, -1, capturePacket, NULL);
    if (packet_count == -1) {
        printf("Error occurred during packet capture: %s\n", pcap_geterr(handle));
        return 3;
    }

    /* Close the handle */
    pcap_close(handle);

    return 0;
}