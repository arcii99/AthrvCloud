//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    printf("Listening on device: %s\n", dev);

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received a packet with length of [%d]\n", header->len);
}