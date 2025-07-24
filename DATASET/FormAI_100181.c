//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int ret;

    printf("Starting network packet monitoring!\n");

    // open device for live capture
    handle = pcap_open_live("eth0", BUFSIZ, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // capture and print packets
    while ((ret = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (ret == 0) continue;
        printf("Packet captured! Length: %d\n", header->len);
        // TODO: add custom packet analysis here
    }

    // cleanup
    pcap_close(handle);
    printf("Stopped network packet monitoring.\n");
    return 0;
}