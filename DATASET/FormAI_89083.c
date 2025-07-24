//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define snaplen 65535
#define promisc 1
#define to_ms 1000

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    char *data;
    int datalen = pkthdr->len;

    printf("\nPacket Length: %d ", datalen);

    /* Print packet in hex format */
    for (int i = 0; i < datalen; i++)
    {
        if (i % 16 == 0)
            printf("\n");
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    /* Find a network device to capture packets */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return (2);
    }

    printf("Capturing packets on device: %s\n", dev);

    /* Open the network interface */
    handle = pcap_open_live(dev, snaplen, promisc, to_ms, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return (2);
    }

    /* Capture 10 packets and pass to the callback function */
    if (pcap_loop(handle, 10, packetHandler, NULL) == -1)
    {
        fprintf(stderr, "Error in pcap_loop(): %s\n", pcap_geterr(handle));
        return (2);
    }

    /* Close the network interface */
    pcap_close(handle);

    return (0);
}