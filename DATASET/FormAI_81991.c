//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cryptic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // process packet
    printf("Packet captured.\n");
}

int main(int argc, char **argv) {
    char *dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(1);
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        fprintf(stderr, "Device %s doesn't provide Ethernet headers - not supported\n", dev);
        return(1);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return(0);
}