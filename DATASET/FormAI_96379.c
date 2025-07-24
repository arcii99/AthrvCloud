//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: imaginative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char const *argv[])
{
    char *dev = NULL; /* Device to sniff on */
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    /* Find a capture device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL)
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    }

    /* Open device for capturing */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    }

    /* Capture packets */
    if (pcap_loop(handle, 0, callback, NULL) < 0)
    {
        fprintf(stderr, "pcap_loop failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    /* Free resources */
    pcap_close(handle);

    return 0;
}

void callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;

    /* Display the packet number */
    printf("Packet number %d:\n", count++);
    printf("-----------------------------------------\n");

    /* Process the packet */
    for (int i = 0; i < header->caplen; i++)
    {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }

    printf("\n=========================================\n");
}