//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> 

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet);

int main(int argc, char *argv[]) 
{
    pcap_t *handle;         // pcap handle 
    char *dev;              // device to capture packets on 
    char errbuf[PCAP_ERRBUF_SIZE];      // error buffer 

    // Get the first available network device 
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(-1);
    }

    // Open the device for packet capture 
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(-1);
    }

    // Enter the capture loop 
    if (pcap_loop(handle, -1, packet_handler, NULL) < 0) {
        fprintf(stderr, "Error during capture: %s\n", pcap_geterr(handle));
        return(-1);
    }

    // Close the handle 
    pcap_close(handle);
    return(0);
}

// Callback function for pcap_loop, called on each captured packet 
void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    printf("Received packet of length %d\n", pkthdr->len);
}