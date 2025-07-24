//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: single-threaded
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *data) {
    // This is where packet analysis code would go
    printf("Packet captured!\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    bpf_u_int32 subnet_mask, ip;

    // Open device for live capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    pcap_compile(handle, &filter, "port 80", 1, ip);
    pcap_setfilter(handle, &filter);

    // Start packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    return 0;
}