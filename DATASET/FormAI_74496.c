//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multivariable
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // This function will be called each time we capture a packet
    // We can put our packet processing code here
    printf("New packet captured!\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for pcap
    pcap_t *handle; // Packet capture handle
 
    // Start capturing packets on all interfaces
    handle = pcap_open_live("any", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return -1;
    }
 
    // Set a filter to capture only TCP packets
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }
 
    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);
 
    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);
 
    return 0;
}