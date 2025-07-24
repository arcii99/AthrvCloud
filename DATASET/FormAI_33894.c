//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <pcap.h>
#include <stdio.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        fprintf(stderr, "Device %s doesn't provide Ethernet headers - not supported\n", pcap_lookupdev(errbuf));
        return 1;
    }

    printf("Starting packet capture on device %s\n", pcap_lookupdev(errbuf));

    pcap_loop(handle, -1, got_packet, NULL);

    pcap_close(handle);
    return 0;
}