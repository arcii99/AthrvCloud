//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <pcap.h> // Include pcap library
 
void packetHandlerFun(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    // Callback function to print packet information
    printf("Packet capture length: %d\n", pkthdr->caplen);
    printf("Number of bytes present in the packet: %d\n", pkthdr->len);
}
 
int main(int argc, char** argv) {
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
 
    // Open capture interface
    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf); // Change en0 to your network interface
    
    if (handle == NULL) {  // Catch errors opening the interface
        printf("Error opening device %s: %s\n", "en0", errbuf);
        return 1;
    }
    
    // Capture packets
    pcap_loop(handle, -1, packetHandlerFun, NULL);
 
    printf("Packet capture completed!\n");
 
    return 0;
}