//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char* unused_param, const struct pcap_pkthdr* packet_header, const u_char* packet_data) {
    printf("Received a packet on this interface!\n");
}

int main() {
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 10;
    int timeout_limit = 10000;

    // Step 1: Open a device for capturing
    handle = pcap_open_live("eth0", BUFSIZ, 1, timeout_limit, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device eth0: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Step 2: Compile and apply filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter expression '%s': %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not apply filter expression '%s': %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Step 3: Capture packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Step 4: Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Done capturing packets!\n");
    return 0;
}