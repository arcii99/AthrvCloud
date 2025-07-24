//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: puzzling
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv)
{
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Device: %s\n", dev);

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_loop(handle, -1, packet_handler, NULL) < 0)
    {
        fprintf(stderr, "pcap_loop failed: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;
    printf("\nPacket number %d:\n", count);
    count++;

    printf("Packet length: %d\n", header->len);
    printf("Number of bytes: %d\n", header->caplen);

    for (int i = 0; i < header->caplen; i++)
    {
        printf("%.2x ", packet[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n\n");
}