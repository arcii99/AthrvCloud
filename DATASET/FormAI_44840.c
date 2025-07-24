//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <pcap.h>
#include <stdio.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    printf("Packet captured at %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));
    printf("Packet length: %d\n", pkthdr->len);
    
    // Your code here
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char* device = pcap_lookupdev(errbuf); // Get default device
    
    if(device == NULL) {
        printf("Error finding default device: %s\n", errbuf);
        return 1;
    }
    
    printf("Using device: %s\n", device);
    
    pcap_t* handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf); // Open device for live capture
    
    if(handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }
    
    printf("Packet capturer started.\n");
    
    pcap_loop(handle, 0, packetHandler, NULL); // Capture packets indefinitely
    
    pcap_close(handle); // Close handle
    
    return 0;
}