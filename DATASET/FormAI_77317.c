//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: peaceful
#include <pcap.h>
#include <stdio.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main() {
    pcap_t *handle;         //session handle
    char *dev;              //network device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];  //buffer to hold error message
    
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(1);
    }
    
    printf("Sniffing on device: %s\n", dev);
    
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(1);
    }
    
    pcap_loop(handle, -1, process_packet, NULL);
    
    pcap_close(handle);
    
    return(0);
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    printf("Packet captured of length %d\n", header->len);
    //add your packet processing code here
}