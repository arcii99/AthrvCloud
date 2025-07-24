//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAXBYTES2CAPTURE 2048

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    struct iphdr *ipHeader;
    struct tcphdr *tcpHeader;
    int inIpHeaderSize;
    int tcpHeaderSize;
    char sourceIp[INET_ADDRSTRLEN];
    char destIp[INET_ADDRSTRLEN];

    // Initialize IP header
    ipHeader = (struct iphdr*) packet;
    inIpHeaderSize = ipHeader->ihl * 4;

    // Check if protocol is TCP
    if (ipHeader->protocol == IPPROTO_TCP) {
        // Initialize TCP header
        tcpHeader = (struct tcphdr*) (packet + inIpHeaderSize);
        tcpHeaderSize = tcpHeader->doff * 4;

        // Convert source address and destination address to string
        inet_ntop(AF_INET, &(ipHeader->saddr), sourceIp, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ipHeader->daddr), destIp, INET_ADDRSTRLEN);

        // Print packet information
        printf("Source IP: %s\n", sourceIp);
        printf("Destination IP: %s\n", destIp);
        printf("Source Port: %d\n", ntohs(tcpHeader->source));
        printf("Destination Port: %d\n", ntohs(tcpHeader->dest));
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int i;
    char *device;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filterString[] = "tcp";
    bpf_u_int32 subnetMask;
    bpf_u_int32 networkAddress;

    // Determine device to sniff
    device = pcap_lookupdev(errorBuffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", errorBuffer);
        return 1;
    }

    // Print device name
    printf("Device: %s\n", device);

    // Open device for sniffing
    handle = pcap_open_live(device, MAXBYTES2CAPTURE, 1, 512, errorBuffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errorBuffer);
        return 1;
    }

    // Get network address and subnet mask of device
    if (pcap_lookupnet(device, &networkAddress, &subnetMask, errorBuffer) == -1) {
        printf("Error getting device information: %s\n", errorBuffer);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &filter, filterString, 0, networkAddress) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Assign the compiled filter to the packet capture handle
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the session
    pcap_close(handle);

    return 0;
}