//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_analysis(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured length: %d\n", header->len);
}

int main(int argc, char *argv[]) {
    char *dev = "eth0"; // Change this according to your own system interface
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int snapshot_length = 1024;
    int promiscuous = 0;
    int timeout = 1000;

    handle = pcap_open_live(dev, snapshot_length, promiscuous, timeout, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    pcap_loop(handle, -1, packet_analysis, NULL);

    pcap_close(handle);

    return EXIT_SUCCESS;
}