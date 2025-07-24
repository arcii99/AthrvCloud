//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet){
    int ethernetHeaderLength = 14;
    struct iphdr *ipHeader = (struct iphdr*)(packet + ethernetHeaderLength);
    unsigned short ipHeaderLength = ipHeader->ihl * 4;

    struct tcphdr *tcpHeader = (struct tcphdr*)(packet + ethernetHeaderLength + ipHeaderLength);
    struct udphdr *udpHeader = (struct udphdr*)(packet + ethernetHeaderLength + ipHeaderLength);

    if(ipHeader->protocol == IPPROTO_ICMP){
        printf("\n\n*****************ICMP Packet*************************\n\n");

        printf("\n\n******************************************************\n\n");
    }

    if(ipHeader->protocol == IPPROTO_TCP){
        printf("\n\n*****************TCP Packet*************************\n\n");

        printf("Source Port: %d\n", ntohs(tcpHeader->source));
        printf("Destination Port: %d\n", ntohs(tcpHeader->dest));

        printf("\n\n******************************************************\n\n");
    }

    if(ipHeader->protocol == IPPROTO_UDP){
        printf("\n\n*****************UDP Packet*************************\n\n");

        printf("Source Port: %d\n", ntohs(udpHeader->source));
        printf("Destination Port: %d\n", ntohs(udpHeader->dest));

        printf("\n\n******************************************************\n\n");
    }
}

int main() {
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", MAX_PACKET_SIZE, 1, 0, errorBuffer);

    if (handle == NULL) {
        printf("Error opening network interface: %s", errorBuffer);
        exit(1);
    }

    printf("Listening on device: %s\n", pcap_lookupdev(errorBuffer));

    pcap_loop(handle, -1, packetHandler, NULL);
    pcap_close(handle);
    return 0;
}