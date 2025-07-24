//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <string.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;

    if (argc < 2) {
        printf("Usage: %s [pcap_filter_expression]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(EXIT_FAILURE);
    }

    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, argv[1], 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", argv[1], pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", argv[1], pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    if (pcap_loop(handle, 0, packet_handler, NULL) == -1) {
        fprintf(stderr, "Error in pcap_loop: %s\n", pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    pcap_freecode(&fp);
    pcap_close(handle);

    printf("\nCapture complete.\n");

    return(EXIT_SUCCESS);
}


void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {    
    static int count = 1;
    struct ip *ip_hdr;
    struct tcphdr *tcp_hdr;
    char source_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    printf("\nPacket number %d:\n", count);

    ip_hdr = (struct ip*)(pkt_data + SIZE_ETHERNET);
    inet_ntop(AF_INET, &(ip_hdr->ip_src), source_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_hdr->ip_dst), dest_ip, INET_ADDRSTRLEN);
    printf("Source IP: %s\n", source_ip);
    printf("Destination IP: %s\n", dest_ip);

    if (ip_hdr->ip_p == IPPROTO_TCP) {
        tcp_hdr = (struct tcphdr*)(pkt_data + SIZE_ETHERNET + (ip_hdr->ip_hl << 2));
        printf("Source Port: %d\n", ntohs(tcp_hdr->source));
        printf("Destination Port: %d\n", ntohs(tcp_hdr->dest));
    }

    count++;
}