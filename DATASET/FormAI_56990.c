//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: visionary
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
 
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    struct ether_header *ethHeader;
    ethHeader = (struct ether_header*)packet;
 
    if (ntohs(ethHeader->ether_type) == ETHERTYPE_IP)
    {
        printf("Captured an IP packet\n");
    }
    else if (ntohs(ethHeader->ether_type) == ETHERTYPE_ARP)
    {
        printf("Captured an ARP packet\n");
    }
    else if (ntohs(ethHeader->ether_type) == ETHERTYPE_REVARP)
    {
        printf("Captured a Reverse ARP packet\n");
    }
    else
    {
        printf("Unknown packet type\n");
    }
}
 
int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter[] = "tcp";
    bpf_u_int32 net = 0;
    bpf_u_int32 mask = 0;
 
    // Get network device
    char *dev = pcap_lookupdev(errbuf);
 
    // Get network device properties
    pcap_lookupnet(dev, &net, &mask, errbuf);
 
    // Open device for capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
 
    // Compile filter expression
    pcap_compile(handle, &fp, filter, 0, net);
 
    // Set filter for the device capture
    pcap_setfilter(handle, &fp);
 
    // Start packet capture
    pcap_loop(handle, -1, packetHandler, NULL);
 
    // Close device
    pcap_close(handle);
    return 0;
}