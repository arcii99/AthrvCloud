//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // Avoiding unused parameter warning
    (void)(userData);

    printf("==== NEW PACKET ====\n");

    // Printing length of packet in bytes
    printf("Packet length: %d\n", pkthdr->len);

    // Printing packet data hexadecimal representation
    for (int i = 0; i < pkthdr->len; ++i)
    {
        printf("%02x ", packet[i]);

        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main()
{
    pcap_t *pcap;
    char errbuf[PCAP_ERRBUF_SIZE];
    const char *dev;

    // Finding default device to capture packets on
    dev = pcap_lookupdev(errbuf);

    // Check for errors
    if (dev == NULL)
    {
        fprintf(stderr, "PCAP Lookup Device Error: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Device: %s\n", dev);

    // Opening the device in promiscuous mode
    pcap = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    // Check for errors
    if (pcap == NULL)
    {
        fprintf(stderr, "PCAP Open Live Error: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Capturing packets until user interrupts
    pcap_loop(pcap, -1, packetHandler, NULL);

    return EXIT_SUCCESS;
}