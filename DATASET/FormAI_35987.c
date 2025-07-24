//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#define ETHER_ADDR_LEN 6

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;                   // packet counter
    const struct ether_header* ethernet;    // ethernet header
    const struct iphdr* ip;                 // IP header
    const struct tcphdr* tcp;               // TCP header
    u_int size_ip;
    u_int size_tcp;
    
    ethernet = (struct ether_header*)(packet);
    if (ntohs(ethernet->ether_type) == ETHERTYPE_IP)       // check if IP packet
    {
        ip = (struct iphdr*)(packet + sizeof(struct ether_header));
        size_ip = ip->ihl * 4;
        if (size_ip < 20) {
            fprintf(stderr, "Invalid IP header length: %u bytes\n", size_ip);
            return;
        }
        
        tcp = (struct tcphdr*)(packet + sizeof(struct ether_header) + size_ip);
        size_tcp = tcp->doff * 4;
        if (size_tcp < 20) {
            fprintf(stderr, "Invalid TCP header length: %u bytes\n", size_tcp);
            return;
        }
        
        printf("\nPacket number %d:\n-----------------\n", count++);
        printf("Source Address: %s\n", ether_ntoa((struct ether_addr*)ethernet->ether_shost));
        printf("Destination Address: %s\n", ether_ntoa((struct ether_addr*)ethernet->ether_dhost));
        printf("Protocol: IP (%d)\n", ntohs(ip->protocol));
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&ip->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&ip->daddr));
        printf("Source Port: %d\n", ntohs(tcp->source));
        printf("Destination Port: %d\n", ntohs(tcp->dest));
    }
}

int main(int argc, char **argv)
{
    char *dev = NULL, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(1);
    }
    
    printf("Device: %s\n", dev);
    
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
    
    printf("Listening on device: %s\n", dev);
    
    pcap_loop(handle, -1, got_packet, NULL);
    pcap_close(handle);

    printf("\nCapture complete.\n");

    return(0);
}