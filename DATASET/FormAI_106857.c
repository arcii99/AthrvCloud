//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Handle the packet here
    
    printf("Packet captured of length %d\n", header->len);
}

int main(int argc, char **argv) {
    char *device;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int numPackets = 10; // Number of packets to capture
    
    if(argc < 2) {
        // Get the default network device
        device = pcap_lookupdev(errorBuffer);
        if(device == NULL) {
            printf("Error finding default network device: %s\n", errorBuffer);
            return 1;
        }
    } else {
        device = argv[1];
    }
    
    printf("Using network device: %s\n", device);
    
    // Open the network device for packet capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errorBuffer);
    if(handle == NULL) {
        printf("Error opening network device: %s\n", errorBuffer);
        return 1;
    }
    
    // Capture packets
    pcap_loop(handle, numPackets, packetHandler, NULL);
    
    // Close the handle
    pcap_close(handle);
    
    printf("Packet capture complete.\n");
    
    return 0;
}