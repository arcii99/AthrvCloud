//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net;
    int num_packets = 10;
    struct pcap_pkthdr header;
    const u_char *packet;
    int i;

    // Open the capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", "eth0", errbuf);
        return(1);
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Couldn't compile filter: %s\n", pcap_geterr(handle));
        return(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        return(1);
    }

    // Capture packets
    for (i = 0; i < num_packets; i++) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            printf("No packet found.\n");
            continue;
        }
        printf("Packet #%d:\n", i+1);
        printf("    Length: %d\n", header.len);
    }

    // Close the capture device
    pcap_close(handle);

    return(0);
}