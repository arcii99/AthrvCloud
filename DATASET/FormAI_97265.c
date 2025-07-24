//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    struct ether_header* ethernetHeader;
    struct ip* ipHeader;
    char sourceIp[INET_ADDRSTRLEN];
    char destinationIp[INET_ADDRSTRLEN];

    // Parse the Ethernet header information
    ethernetHeader = (struct ether_header*) packetData;

    // Verify that the packet contains an IP header
    if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) {
        // Parse the IP header information
        ipHeader = (struct ip*)(packetData + sizeof(struct ether_header));
        inet_ntop(AF_INET, &(ipHeader->ip_src), sourceIp, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ipHeader->ip_dst), destinationIp, INET_ADDRSTRLEN);

        // Print out the source and destination IP addresses
        printf("Source IP: %s\n", sourceIp);
        printf("Destination IP: %s\n", destinationIp);
    }
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* pcapHandle;
    char* deviceName = pcap_lookupdev(errbuf);

    // Open the network device for packet capture
    pcapHandle = pcap_open_live(deviceName, BUFSIZ, 0, -1, errbuf);

    // Set the packet capture filter expression
    struct bpf_program filter;
    pcap_compile(pcapHandle, &filter, "ip", 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(pcapHandle, &filter);

    // Start the packet capture loop
    pcap_loop(pcapHandle, -1, packet_handler, NULL);

    // Close the packet capture handle
    pcap_close(pcapHandle);

    return 0;
}