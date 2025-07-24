//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char *device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }
    
    printf("Capturing packets on device %s\n", device);
    
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device for capture: %s\n", errbuf);
        return 1;
    }
    
    struct pcap_pkthdr header;
    const u_char *packet;
    
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) continue;
        printf("Packet received! Length: %d\n", header.len);
        for (int i = 0; i < header.len; i++) {
            if (i % 16 == 0) printf("\n");
            printf("%02x ", packet[i]);
        }
    }
    
    pcap_close(handle);
    return 0;
}