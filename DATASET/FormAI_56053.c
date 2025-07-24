//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        printf("Error finding device: %s\n",errbuf);
        return 1;
    }
    printf("Device: %s\n",device);
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n",errbuf);
        return 1;
    }
    struct pcap_pkthdr header;
    const u_char *packet;

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet Captured with length: %d\n", header.len);
        }
    }

    pcap_close(handle);
    return 0;
}