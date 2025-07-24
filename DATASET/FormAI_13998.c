//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) 
{
    printf("Packet size: %d bytes\n", pkthdr->len);
}

int main(int argc, char const *argv[])
{
    char pcapErrBuf[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    pcap_t *pcapHandle; // Handle for pcap library
    const char *dev; // Device pointer to loop through devices
    
    // Search for available network devices
    dev = pcap_lookupdev(pcapErrBuf);
    if (dev == NULL) {
        // Could not find any device
        printf("Error finding device: %s\n", pcapErrBuf);
        return 1;
    }
    printf("Device found: %s\n",dev);
    
    // Open the device for packet capture
    pcapHandle = pcap_open_live(dev, 65536, 1, 1000, pcapErrBuf);
    if (pcapHandle == NULL) {
        // Could not open device for packet capture
        printf("Error opening device for capture: %s\n", pcapErrBuf);
        return 1;
    }
    
    // Loop through packets to capture
    pcap_loop(pcapHandle, -1, packetHandler, NULL);
    
    // Close the capture session
    pcap_close(pcapHandle);
    
    return 0;
}