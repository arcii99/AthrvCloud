//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer for pcap functions
    char *device = pcap_lookupdev(errbuf); // find device for packet capture
    if(device == NULL) { // if no device found, print error
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    
    printf("Capturing on device: %s\n", device); // print device name
    
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf); // open handle for packet capture
    if(handle == NULL) { // if handle couldn't be opened, print error
        printf("Couldn't open device %s: %s\n", device, errbuf);
        return 1;
    }
    
    while(1) { // loop for capturing packets continuously
        struct pcap_pkthdr header; // pcap header for capturing packet's metadata
        const u_char *packet = pcap_next(handle, &header); // capture next packet
        
        printf("Packet captured %d bytes\n", header.len); // print packet size in bytes
        
        /*
        Here you can add custom code to process the packet captured.
        */
    }
    
    pcap_close(handle); // close the handle for packet capture
    
    return 0; // exit program with no error
}