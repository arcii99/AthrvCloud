//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: minimalist
#include <pcap.h> // Library for packet capture functionality
#include <stdio.h> // Standard I/O library
#include <stdlib.h> // Includes functions for allocating and deallocating memory

void packetHandler(unsigned char *userData, const struct pcap_pkthdr* pkthdr, const unsigned char* packet);

int main()
{
    char errbuffer[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    struct bpf_program fp; // The compiled filter
    char filter_exp[] = "port 80"; // Filter expression
    bpf_u_int32 subnet_mask; // The subnet mask of our network
    bpf_u_int32 ip; // The IP of our network

    // Find the properties for the network
    if (pcap_lookupnet("eth0", &ip, &subnet_mask, errbuffer) == -1)
    {
        printf("Could not get network information\n");
        return 1;
    }

    // Open the session in promiscuous mode
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuffer);
    if (handle == NULL)
    {
        printf("Could not open device\n");
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1)
    {
        printf("Could not parse filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1)
    {
        printf("Could not apply filter\n");
        return 1;
    }

    // Capture packets and print results
    pcap_loop(handle, -1, packetHandler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}

void packetHandler(unsigned char *userData, const struct pcap_pkthdr* pkthdr, const unsigned char* packet)
{
    // Print the packet length
    printf("Packet length: %d\n", pkthdr->len);
}