//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: immersive
#include <stdio.h>
#include <pcap.h>

/* This program monitors network packets using pcap library,
displays the captured packets and filters by IP address and protocol type. */

int main() {

    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer
    pcap_t *handle; // capture handle
    struct bpf_program fp; // compiled filter program (expression)
    char filter_exp[] = "host 192.168.0.1 and tcp"; // filter expression
    bpf_u_int32 mask; // subnet mask
    bpf_u_int32 net; // ip address
    struct pcap_pkthdr header; // packet header
    const u_char *packet; // packet data
    int packet_counter = 0; // count packets

    // find network interface to capture packets
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev);

    // find the network IP address and subnet mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open a handle to the capture device with 100ms timeout
    handle = pcap_open_live(dev, BUFSIZ, 1, 100, errbuf);
    if (handle == NULL) {
        printf("Couldn't capture packets: %s\n", errbuf);
        return 1;
    }

    // compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't compile filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // loop through packets and display information
    while (packet = pcap_next(handle, &header)) {
        packet_counter++;
        printf("Packet #%d\n", packet_counter);
        printf("Timestamp: %ld.%06ld\n", header.ts.tv_sec, header.ts.tv_usec);
        printf("Length: %d\n\n", header.len);
    }

    // cleanup and close capture handle
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}