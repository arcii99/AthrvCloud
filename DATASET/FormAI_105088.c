//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;
    printf("\nPacket number %d:\n", count);
    printf("Received packet size: %d\n", header->len);
    count++;
}

int main(int argc, char *argv[])
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    int num_packets = -1;

    // Find a valid network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Could not find a networking device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev);

    // Open a network device for packet capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, num_packets, callback, NULL);

    // Close the capture device
    pcap_close(handle);

    return 0;
}