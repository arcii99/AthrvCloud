//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

// Callback function for packet capture
void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packetData)
{
    // Print timestamp and length of the packet
    printf("%ld:%ld (%ld)\n", pkthdr->ts.tv_sec, pkthdr->ts.tv_usec, pkthdr->len);
    
    // Extract Ethernet header data
    const u_char *ethernetHeader;
    ethernetHeader = packetData;
    
    // Print source and destination MAC addresses
    printf("Source MAC Address: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
            ethernetHeader[0], ethernetHeader[1], ethernetHeader[2],
            ethernetHeader[3], ethernetHeader[4], ethernetHeader[5]);
    printf("Destination MAC Address: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
            ethernetHeader[6], ethernetHeader[7], ethernetHeader[8],
            ethernetHeader[9], ethernetHeader[10], ethernetHeader[11]);
    
    // Extract IP header data
    const u_char *ipHeader;
    int headerSize;
    ipHeader = packetData + 14; // Skip Ethernet header which is 14 bytes
    headerSize = ((*(u_char *)(ipHeader + 1)) & 0x0F) * 4; // IP header size is in the first nibble of byte 2
    
    // Print source and destination IP addresses
    printf("Source IP Address: %d.%d.%d.%d\n",
            ipHeader[12], ipHeader[13], ipHeader[14], ipHeader[15]);
    printf("Destination IP Address: %d.%d.%d.%d\n",
            ipHeader[16], ipHeader[17], ipHeader[18], ipHeader[19]);
    
    // Extract TCP header data
    const u_char *tcpHeader;
    int tcpHeaderSize;
    tcpHeader = packetData + 14 + headerSize; // Skip Ethernet and IP headers
    tcpHeaderSize = (*(u_char *)(tcpHeader + 12) >> 4) * 4; // TCP header size is in the first nibble of byte 13
    
    // Print source and destination ports
    printf("Source Port: %d\n",
            ((*(u_char *)(tcpHeader + 0)) << 8) + *(u_char *)(tcpHeader + 1));
    printf("Destination Port: %d\n",
            ((*(u_char *)(tcpHeader + 2)) << 8) + *(u_char *)(tcpHeader + 3));
    
    printf("\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap;
    struct bpf_program filter;
    char filterExp[] = "tcp and port 80";
    bpf_u_int32 subnetMask, ip;
    
    // Get default network interface
    char *interface = pcap_lookupdev(errbuf);
    if (interface == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }
    
    // Get IP and subnet mask of the interface
    if (pcap_lookupnet(interface, &ip, &subnetMask, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }
    
    // Open packet capture session
    pcap = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (pcap == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }
    
    // Compile and set the filter expression
    if (pcap_compile(pcap, &filter, filterExp, 0, ip) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(pcap));
        exit(1);
    }
    if (pcap_setfilter(pcap, &filter) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(pcap));
        exit(1);
    }
    
    // Start packet capture loop
    pcap_loop(pcap, -1, packetHandler, NULL);
    
    // Close session and free resources
    pcap_freecode(&filter);
    pcap_close(pcap);
    
    return 0;
}