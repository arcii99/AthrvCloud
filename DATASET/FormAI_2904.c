//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surprised
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer
    pcap_t *handle; // packet capture handle
    
    printf("Surprise! Welcome to the unique C Packet Capturer!\n");

    // open the network device for capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf); 

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    printf("Capturing packets on device: %s\n\n", argv[1]);
    printf("Packet Capturing in progress...\n\n");

    // set the filter expression
    struct bpf_program fp; // compiled filter program
    char filter_exp[] = "port 80"; // capture only HTTP traffic
    bpf_u_int32 mask; // subnet mask
    bpf_u_int32 net; // IP

    // get the network and subnet mask properties
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }

    // compile the filter expression and apply it to the handle
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // start packet capturing
    struct pcap_pkthdr header; // packet header
    const u_char *packet; // captured packet

    while (1) {
        packet = pcap_next(handle, &header);
        printf("Packet Captured! Length: %d\n\n", header.len);
    }

    // close the handle
    pcap_close(handle);
    return 0;
}