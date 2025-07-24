//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: ultraprecise
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured of size %d\n", header->len);
}

int main(int argc, char **argv)
{
    pcap_t *pcap_handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    char *device;

    device = pcap_lookupdev(error_buffer);

    if(device == NULL)
    {
        printf("Error finding device: %s\n", error_buffer);
        return -1;
    }

    printf("Device found: %s\n", device);

    pcap_handle = pcap_open_live(device, BUFSIZ, 0, 1000, error_buffer);

    if(pcap_handle == NULL)
    {
        printf("Error opening device %s: %s\n", device, error_buffer);
        return -1;
    }

    if(pcap_datalink(pcap_handle) != DLT_EN10MB)
    {
        printf("Device %s doesn't provide Ethernet headers - not supported\n", device);
        return -1;
    }

    pcap_loop(pcap_handle, 0, packet_handler, NULL);

    pcap_close(pcap_handle);

    return 0;
}