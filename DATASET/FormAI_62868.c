//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Cryptic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

/* Callback function to read packets */
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {

    /* Print packet size */
    printf("Packet size: %d bytes\n", pkthdr->len);
    
    /* Do something with the packet */
    // ...
}

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filterExpression[] = "ip";
    bpf_u_int32 subnetMask, ipAddress;

    /* Find the default interface */
    char *device = pcap_lookupdev(errbuf);

    /* Get network address and subnet mask */
    pcap_lookupnet(device, &ipAddress, &subnetMask, errbuf);

    /* Open the device to sniff packets */
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    /* Compile and apply the filter to the network interface */
    pcap_compile(handle, &filter, filterExpression, 0, subnetMask);
    pcap_setfilter(handle, &filter);

    /* Start capturing packets */
    pcap_loop(handle, -1, packetHandler, NULL);

    /* Clean up */
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}