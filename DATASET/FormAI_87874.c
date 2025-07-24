//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <pcap.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *dev = argv[1]; // Capture device name
    pcap_t *handle; // Session handle
    char errbuf[PCAP_ERRBUF_SIZE]; // Error string
    struct bpf_program fp; // The compiled filter expression
    char filter_exp[] = "tcp port 80"; // The filter expression
    bpf_u_int32 mask; // The netmask of our sniffing device
    bpf_u_int32 net; // The IP of our sniffing device
    struct pcap_pkthdr header; // The header that pcap gives us
    const u_char *packet; // The actual packet

    // Step 1: Open live capture session on device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Step 2: Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Step 3: Set filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Step 4: Capture packets
    packet = pcap_next(handle, &header);
    printf("Jacked a packet with length of [%d]\n", header.len);

    // Step 5: Close session
    pcap_close(handle);
    return(0);
}