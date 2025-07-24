//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user_args, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
    printf("Packet captured of length %d\n", pkt_header->len);
}

int main(int argc, char **argv)
{
    char *dev; // name of device to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer
    pcap_t *descr; // pcap descriptor

    // determines which device to capture packets from
    dev = pcap_lookupdev(errbuf);

    // error check for device
    if (dev == NULL)
    {
        printf("%s\n", errbuf);
        exit(1);
    }

    // opens device for packet capture
    descr = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);

    // error check for descriptor
    if (descr == NULL)
    {
        printf("pcap_open_live(): %s\n", errbuf);
        exit(1);
    }

    // captures packets continuously
    if (pcap_loop(descr, 0, packet_handler, NULL) < 0)
    {
        printf("pcap_loop(): %s\n", pcap_geterr(descr));
        exit(1);
    }

    // closes packet capture
    pcap_close(descr);

    return 0;
}