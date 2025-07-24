//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", "eth0", errbuf);
        return -1;
    }

    struct pcap_pkthdr header;
    const u_char *packet;

    printf("My dear packet, I will monitor you forever.\n");

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) continue;

        printf("Packet captured - length %d bytes\n", header.len);
    }

    pcap_close(handle);
    return 0;
}