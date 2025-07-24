//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured! Length: %d\n", header->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    char *device = pcap_lookupdev(errbuf);

    if (device == NULL) {
        printf("Error finding device: %s\n", errbuf);
        return -1;
    }

    printf("Using device: %s\n", device);

    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return -1;
    }

    printf("Capturing packets...\n");

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);

    printf("Packet capture complete.\n");

    return 0;
}