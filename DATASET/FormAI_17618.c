//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: portable
#include <stdio.h>  
#include <pcap.h>  
#include <stdlib.h>   
#include <string.h>  
#include <ctype.h>  
#include <errno.h>   
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Implement packet processing logic here.
}

int main(int argc, char *argv[]) {
    char *dev = NULL;   // Device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];  // Error string buffer
    pcap_t *handle; // Session handle
    bpf_u_int32 mask;   // Netmask of sniffing device
    bpf_u_int32 net;    // IP of sniffing device
    struct bpf_program filter;  // The compiled filter
    char filter_exp[] = "tcp port 80";  // The filter expression
    int num_packets = 10;   // Number of packets to capture

    // Check for device argument
    if(argc > 1) {
        dev = argv[1];
    }
    else {
        // Get first available device
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return(2);
        }
    }

    // Get network number and mask of device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Compile filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Apply filter expression
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Capture packets
    pcap_loop(handle, num_packets, got_packet, NULL);

    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    printf("Capture complete.\n");

    return 0;
}