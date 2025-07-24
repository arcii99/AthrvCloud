//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv)
{
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Error finding device: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    printf("Listening on %s...\n", dev);
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }
    pcap_loop(handle, 0, packetHandler, NULL);
    pcap_close(handle);
    return EXIT_SUCCESS;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Received packet of length: %d\n", pkthdr->len);
    // print raw packet data
    for (int i=0; i<pkthdr->len; i++) {
        printf("%.2x ", packet[i]);
        if ((i+1)%16 == 0){
            printf("\n");
        }
    }
    printf("\n\n");
}