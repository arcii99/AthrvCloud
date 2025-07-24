//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // Print packet timestamp and length
    printf("Packet capture length: %d\n", pkthdr->caplen);
    printf("Packet total length: %d\n", pkthdr->len);
    printf("Packet timestamp: %s", ctime((const time_t*)&pkthdr->ts.tv_sec));
    
    // Print packet data as hex
    for(int i=0; i<pkthdr->len; i++)
    {
        printf("%.2x ", packet[i]);
        
        // Print 16 bytes per line
        if((i+1)%16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    char *dev = NULL;             // Device to capture on
    char errbuf[PCAP_ERRBUF_SIZE];   // Error buffer
    pcap_t *handle;               // Packet capture handle
    
    // Get the name of the first available device
    dev = pcap_lookupdev(errbuf);
    
    // Check for errors
    if(dev == NULL)
    {
        fprintf(stderr, "pcap_lookupdev() failed: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    
    printf("Capturing on device %s\n", dev);
    
    // Open device for packet capture
    handle = pcap_open_live(dev, 65535, 1, 0, errbuf);
    
    // Check for errors
    if(handle == NULL)
    {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    
    // Start capturing packets
    printf("Start capturing packets...\n");
    pcap_loop(handle, -1, packetHandler, NULL);
    
    // Close the handle
    pcap_close(handle);
    
    return EXIT_SUCCESS;
}