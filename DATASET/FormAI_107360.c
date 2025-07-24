//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Defining maximum bytes to capture
#define MAXBYTES 65535

int main(int argc, char *argv[])
{
    char *dev;  // The device to capture on
    char errbuf[PCAP_ERRBUF_SIZE]; // Error string
    pcap_t *handle; // Session handle
    struct bpf_program fp; // The compiled filter 
    char filter_exp[] = "port 80"; // The filter expression 
    bpf_u_int32 mask; // Our netmask 
    bpf_u_int32 net; // Our IP 
    struct pcap_pkthdr header; // The header that pcap gives us 
    const u_char *packet; // The actual packet 

    // Define the device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(EXIT_FAILURE);
    }
    printf("Device: %s\n", dev);

    // Find the properties for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, MAXBYTES, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(EXIT_FAILURE);    
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    // Loop through the packets and print them to stdout
    while (packet = pcap_next(handle, &header)) {
        printf("Packet length: %d bytes\n", header.len);
    }

    // Close the session
    pcap_close(handle);

    return(EXIT_SUCCESS);
}