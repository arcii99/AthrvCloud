//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void print_packet_info(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char *dev_name = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // get the device name
    if (argc < 2) {
        dev_name = pcap_lookupdev(errbuf);
        if (dev_name == NULL) {
            printf("No default interface found. Please specify an interface name as a command line argument.\n");
            exit(1);
        }
    } else {
        dev_name = argv[1];
    }

    // open the device for packet capture
    handle = pcap_open_live(dev_name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening interface %s: %s\n", dev_name, errbuf);
        exit(1);
    }

    // capture packets indefinitely
    pcap_loop(handle, -1, print_packet_info, NULL);

    pcap_close(handle);
    return 0;
}

void print_packet_info(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // ignore packets that are not IP packets
    if (ntohs(*(unsigned short*)(packet + 12)) != ETHERTYPE_IP) {
        return;
    }

    // extract the IP header
    const struct iphdr *ip_header = (struct iphdr*)(packet + sizeof(struct ethhdr));
    // ignore packets that are not TCP packets
    if (ip_header->protocol != IPPROTO_TCP) {
        return;
    }

    // extract the TCP header
    const struct tcphdr *tcp_header = (struct tcphdr*)(packet + sizeof(struct ethhdr) + sizeof(struct iphdr));

    // print the packet's source IP, source port, destination IP, and destination port
    printf("%s:%d - %s:%d\n", inet_ntoa(*(struct in_addr*)&ip_header->saddr), ntohs(tcp_header->source),
           inet_ntoa(*(struct in_addr*)&ip_header->daddr), ntohs(tcp_header->dest));
}