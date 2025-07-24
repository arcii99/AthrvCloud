//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char* argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    int timeout = 1000; // in milliseconds
    int packet_count = 0;
    int snaplen = 65535;

    // create a new session
    handle = pcap_open_live(argv[1], snaplen, 1, timeout, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", argv[1], errbuf);
        return -1;
    }

    // set the filter expression
    struct bpf_program fp;
    char filter_exp[] = "tcp and port 80";
    if (pcap_compile(handle, &fp, filter_exp, 0, 0) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    // loop through packets
    struct pcap_pkthdr header;
    const u_char* packet;
    while (packet_count < 10) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet #%d captured, size %d\n", ++packet_count, header.len);
        }
    }

    // clean up
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}