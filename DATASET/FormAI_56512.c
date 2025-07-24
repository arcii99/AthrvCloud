//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetPtr)
{
    struct ether_header *ethHeader;
    ethHeader = (struct ether_header*)packetPtr;    
    printf("Source: %s", ether_ntoa((struct ether_addr*) ethHeader->ether_shost));
    printf("      Destination: %s", ether_ntoa((struct ether_addr*) ethHeader->ether_dhost));
    printf("      Protocol: %d\n", ethHeader->ether_type);
}

int main(int argc, char **argv)
{
    int pktCountLimit = -1;
    char* interface = "eth0";
    struct bpf_program bpfProgram;
    char bpfFilter[] = "tcp and port 80";
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t* pcapHandle = pcap_open_live(interface, BUFSIZ, 1, 0, errbuf);
    if (pcapHandle == NULL) 
    {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(pcapHandle, &bpfProgram, bpfFilter, 0, PCAP_NETMASK_UNKNOWN) == -1) 
    {
        printf("Error: %s\n", pcap_geterr(pcapHandle));
        exit(1);
    }

    if (pcap_setfilter(pcapHandle, &bpfProgram) == -1) 
    {
        printf("Error: %s\n", pcap_geterr(pcapHandle));
        exit(1);
    }

    pcap_loop(pcapHandle, pktCountLimit, packetHandler, NULL);
    pcap_close(pcapHandle);

    return 0;
}