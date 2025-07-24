//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Callback function to be registered for processing captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("\nNew Packet Captured!\n");
    for (int i = 0; i < header->caplen; i++) {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0)
            printf("\n");
    }
}

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *dev;

    // Select network interface to capture packets
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", dev);

    // Open the selected interface for capturing packets
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    // Start capturing the packets from the interface
    printf("Start capturing packets...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the capture handle and free up resources
    pcap_close(handle);

    printf("Done!\n");
    return(0);
}