//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: post-apocalyptic
#include <stdio.h>
#include <pcap.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth = (struct ether_header *) packet;
    struct iphdr *ip = (struct iphdr *) (packet + sizeof(struct ether_header));
    struct tcphdr *tcp = (struct tcphdr *) (packet + sizeof(struct ether_header) + sizeof(struct iphdr));
    
    if (eth->ether_type == ntohs(ETHERTYPE_IP) && ip->protocol == IPPROTO_TCP) {
        printf("Packet captured from the Etherverse. (Size: %d bytes)\n", header->len);
        printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2], eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);
        printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2], eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);
        printf("Source IP address: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
        printf("Destination IP address: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
        printf("Source port: %d\n", ntohs(tcp->source));
        printf("Destination port: %d\n", ntohs(tcp->dest));
        printf("Payload: ");
        for (int i = 0; i < header->len; i++) {
            printf("%02X ", packet[i]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    
    printf("Initializing Network Packet Monitoring program in the post-apocalyptic era...\n");
    
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device eth0: %s\n", errbuf);
        net = 0;
        mask = 0;
    }
    
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device eth0: %s\n", errbuf);
        return 2;
    }
    
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter: %s\n", pcap_geterr(handle));
        return 2;
    }
    
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        return 2;
    }
    
    printf("Starting packet capture...\n");
    
    pcap_loop(handle, -1, packet_handler, NULL);
    
    pcap_freecode(&fp);
    
    pcap_close(handle);
    
    return 0;
}