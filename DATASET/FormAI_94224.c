//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: invasive
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    pcap_t *handle;         // Session handle
    char *dev;              // The device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];  // Error string
    struct bpf_program fp;      // The compiled filter
    char filter_exp[] = "port 80";  // The filter expression
    bpf_u_int32 mask;       // Our netmask
    bpf_u_int32 net;        // Our IP address
    struct pcap_pkthdr header;  // The header that pcap gives us
    const u_char *packet;       // The actual packet
    
    // Define the device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", dev);
    
    // Find the properties for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    
    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
    
    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    
    // Capture packets
    for(int i=1; i<=10; i++) {
        packet = pcap_next(handle, &header);
        printf("Packet #%d:\n", i);
        printf("Length: %d bytes\n", header.len);
        printf("Content:\n");
        for (int j=0; j<header.len; j++) {
            printf("%02x ", packet[j]);
        }
        printf("\n\n");
    }
    
    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);
    
    printf("Finished capturing packets!\n");
    return(0);
}