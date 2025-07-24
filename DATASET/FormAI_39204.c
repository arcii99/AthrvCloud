//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ether.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    //process packet here
    struct ether_header *eth_header = (struct ether_header*)packet;
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));
}

int main(int argc, char *argv[])
{
    char *dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Error getting network information: %s\n", errbuf);
        exit(1);
    }
    descr = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);
    if (descr == NULL)
    {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        exit(1);
    }
    if (pcap_compile(descr, &fp, "tcp", 0, net) == -1)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(descr));
        exit(1);
    }
    if(pcap_setfilter(descr, &fp) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(descr));
        exit(1);
    }
    pcap_loop(descr, 0, packetHandler, NULL);
    pcap_close(descr);
    return 0;
}