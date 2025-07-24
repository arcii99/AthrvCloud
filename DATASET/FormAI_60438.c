//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: visionary
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char const *argv[]) {
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE]; 
    struct bpf_program filter;

    // Step 1: Open capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);

    // Step 2: Compile and apply the filter
    pcap_compile(handle, &filter, "port 80", 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(handle, &filter);

    // Step 3: Start capturing packets
    pcap_loop(handle, -1, process_packet, NULL);

    // Step 4: Cleanup
    pcap_close(handle);
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    printf("Received a packet with length of [%d]\n", header->len);
}