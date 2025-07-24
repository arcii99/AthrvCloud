//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: complex
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    struct ether_header *ethHeader;
    struct iphdr *ipHeader;
    struct tcphdr *tcpHeader;
    u_char *data;
    int dataLength = 0;

    ethHeader = (struct ether_header *) packet;
    if(ntohs(ethHeader->ether_type) == ETHERTYPE_IP) {
        ipHeader = (struct iphdr *) (packet + sizeof(struct ether_header));
        if(ipHeader->protocol == IPPROTO_TCP) {
            tcpHeader = (struct tcphdr *) (packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            data = (u_char *) (packet + sizeof(struct ether_header) + sizeof(struct iphdr) + sizeof(struct tcphdr));
            dataLength = pkthdr->len - (sizeof(struct ether_header) + sizeof(struct iphdr) + sizeof(struct tcphdr));
            printf("\n[*] Packet Captured:");
            printf("\nSource MAC: %s", ether_ntoa((struct ether_addr *) ethHeader->ether_shost));
            printf("\nDestination MAC: %s", ether_ntoa((struct ether_addr *) ethHeader->ether_dhost));
            printf("\nSource IP: %s", inet_ntoa((struct in_addr) {ipHeader->saddr}));
            printf("\nDestination IP: %s", inet_ntoa((struct in_addr) {ipHeader->daddr}));
            printf("\nSource Port: %d", ntohs(tcpHeader->source));
            printf("\nDestination Port: %d", ntohs(tcpHeader->dest));
            printf("\nData Length: %d", dataLength);
            if(dataLength > 0) {
                printf("\nData: ");
                printf("\n%s", data);
            }
        }
    }
}

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnetMask, ipAddress;

    if(pcap_lookupnet("lo", &ipAddress, &subnetMask, errbuf) == -1) {
        printf("\nError: %s", errbuf);
        exit(1);
    }

    handle = pcap_open_live("lo", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        printf("\nError: %s", errbuf);
        exit(1);
    }

    if(pcap_compile(handle, &fp, filter_exp, 0, subnetMask) == -1) {
        printf("\nError: %s", pcap_geterr(handle));
        exit(1);
    }

    if(pcap_setfilter(handle, &fp) == -1) {
        printf("\nError: %s", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, packetHandler, NULL);
    pcap_close(handle);

    return 0;

}