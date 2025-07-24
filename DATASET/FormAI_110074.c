//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <stdio.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char *dev = argv[1]; // name of the device
    char errbuf[PCAP_ERRBUF_SIZE]; // to hold error messages
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    // open device for capturing packets with error handling
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }
    printf("Device opened for capturing packets: %s\n", dev);
    // start capturing packets
    struct pcap_pkthdr header;
    const u_char *packet;
    int count = 0;
    while (count < 5) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet captured: %d bytes\n", header.len);
            count++;
        }
    }
    // close the device and exit
    pcap_close(handle);
    printf("Device closed. %d packets captured.\n", count);
    return 0;
}