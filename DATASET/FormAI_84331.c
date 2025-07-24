//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char *dev = argv[1]; // The device to capture packets on
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *handle; // Session handle
    struct bpf_program fp; // The compiled filter expression
    char filter_exp[] = "port 80"; // Filter expression
    bpf_u_int32 mask; // The netmask of our sniffing device
    bpf_u_int32 net; // The IP of our sniffing device
    struct pcap_pkthdr header; // The header that pcap gives us
    const u_char *packet; // The actual packet

    // Getting the device to capture packets on
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    // Opening the session for capturing packets
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Compiling the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Setting the filter on the session
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Capturing packets
    while (1) {
        packet = pcap_next(handle, &header);
        printf("Got a packet of length %d\n", header.len);
        fflush(stdout);
    }

    // Cleaning up
    pcap_freecode(&fp);
    pcap_close(handle);

    return(0);
}