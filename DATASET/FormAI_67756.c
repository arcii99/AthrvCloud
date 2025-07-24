//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    int i=0;
    printf("Packet #%ld:\n", ++*(unsigned long*)userData);
    for (i=0; (unsigned)i<pkthdr->len; i++)
    {
        printf("%02x%s", packet[i], (i%16==15) ? "\n" : " ");
    }
    printf("\n\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    const char *device = pcap_lookupdev(errbuf);
    if (device == NULL)
    {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }
    printf("Sniffing on device: %s\n", device);

    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    unsigned long packetCount = 0;
    pcap_loop(handle, 10, packet_handler, (u_char*)&packetCount);
    pcap_close(handle);

    printf("Finished processing %ld packets\n", packetCount);
    return 0;
}