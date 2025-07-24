//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: thoughtful
#include <pcap.h>
#include <stdio.h>

#define SNAP_LEN 65535

int main(int argc, char **argv) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    device = pcap_lookupdev(errbuf);

    if (device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    printf("Device: %s\n", device);

    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return 2;
    }

    struct pcap_pkthdr header;
    const u_char *packet;

    packet = pcap_next(handle, &header);
    printf("Packet length: %d\n", header.len);

    pcap_close(handle);

    return 0;
}