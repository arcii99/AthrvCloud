//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: artistic
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    int i;
    printf("Packet Capture Length: %d\n\n", header->caplen);

    /* print the packet in hex */
    for (i = 0; i < header->caplen; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n\n");
}

int main()
{
    char *dev; /* name of the device to use */
    char errbuf[PCAP_ERRBUF_SIZE]; /* error buffer */
    pcap_t *handle; /* packet capture handle */

    /* find a capture device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Using device: %s\n\n", dev);

    /* open the device for packet capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* capture packets */
    printf("Capturing Packets ...\n\n");
    pcap_loop(handle, 0, packetHandler, NULL);

    /* close the capture device */
    pcap_close(handle);

    return 0;
}