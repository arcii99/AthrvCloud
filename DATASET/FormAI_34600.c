//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXBYTES2CAPTURE 2048

void process_packet(u_char *arg, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    int *counter = (int *)arg;

    printf("Packet number %d:\n", ++(*counter));
    printf("Packet length: %d\n", pkthdr->len);
    printf("Number of bytes captured: %d\n", pkthdr->caplen);
    printf("Destination MAC Address: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    printf("Source MAC Address: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);

    switch (ntohs(*(unsigned short *)(packet + 12))) {
        case 0x0800:
            printf("Ethernet type: IP\n");
            break;
        case 0x0806:
            printf("Ethernet type: ARP\n");
            break;
        case 0x8035:
            printf("Ethernet type: RARP\n");
            break;
        default:
            printf("Ethernet type: Unknown\n");
            break;
    }

    printf("\n");
}

int main() 
{
    char errbuf[PCAP_ERRBUF_SIZE];
    int count = 0;
    pcap_t *descr = NULL;
    struct bpf_program fp;
    bpf_u_int32 mask = 0;
    bpf_u_int32 net = 0;

    descr = pcap_open_live("eth0", MAXBYTES2CAPTURE, 1, 512, errbuf);
    if (descr == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        printf("Error looking up net: %s\n", errbuf);
        return 1;
    }

    if (pcap_compile(descr, &fp, "ip", 0, net) == -1) {
        printf("Error compiling the filter: %s\n", pcap_geterr(descr));
        return 1;
    }

    if (pcap_setfilter(descr, &fp) == -1) {
        printf("Error setting the filter: %s\n", pcap_geterr(descr));
        return 1;
    }

    pcap_loop(descr, -1, process_packet, (u_char *)&count);

    return 0;
}