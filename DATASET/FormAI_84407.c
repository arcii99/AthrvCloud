//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: puzzling
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) 
    {
        printf("Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }

    printf("Listening on %s...\n", dev);

    struct pcap_pkthdr header;
    const u_char *packet;
    int pkt_count = 0;

    while (1) 
    {
        packet = pcap_next(handle, &header);

        if (packet == NULL) 
        {
            printf("Packet capture failed\n");
            break;
        }

        printf("Packet %d:\n", ++pkt_count);

        for (int i = 0; i < header.len; i++) 
        {
            printf("%.2X ", packet[i]);
        }

        printf("\n\n");
    }

    pcap_close(handle);
    return 0;
}