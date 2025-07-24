//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Callback function to handle captured packets */
void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // Print packet length
    printf("Packet length: %d\n", pkthdr->len);
    
    // Loop through bytes of packet
    for(int i=0; i < pkthdr->len; i++)
    {
        // Print each byte in hexadecimal
        printf("%02x ", packet[i]);
        
        // Print new line every 16 bytes
        if((i+1) % 16 == 0)
            printf("\n");
    }
    
    printf("\n\n");
}

int main(int argc, char** argv)
{
    char* device; // Pointer to name of capture device
    char errorBuffer[PCAP_ERRBUF_SIZE]; // Buffer for pcap error messages
    pcap_t* handle; // Handle for the device that's being captured
    
    // Get name of capture device
    device = pcap_lookupdev(errorBuffer);
    
    // Make sure device was found
    if(device == NULL)
    {
        fprintf(stderr, "Error finding capture device: %s\n", errorBuffer);
        return 1;
    }
    
    printf("Capturing on device: %s\n\n", device);
    
    // Open capture device for live capture, with maximum packet length of 65535 bytes
    handle = pcap_open_live(device, 65535, 1, 0, errorBuffer);
    
    // Make sure handle was created
    if(handle == NULL)
    {
        fprintf(stderr, "Error opening capture device: %s\n", errorBuffer);
        return 1;
    }
    
    // Enter into a loop to continuously capture packets
    if(pcap_loop(handle, -1, packetHandler, NULL) == -1)
    {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // Close handle and exit program
    pcap_close(handle);
    return 0;
}