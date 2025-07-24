//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include<pcap.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t * handle;
    struct pcap_pkthdr header;
    const unsigned char * packet;
    memset(errbuf, 0, PCAP_ERRBUF_SIZE);
    handle = pcap_open_offline_with_tstamp_precision("test.pcap", PCAP_TSTAMP_PRECISION_MICRO, errbuf);
    if (handle == NULL) 
    {
        fprintf(stderr, "Error opening pcap file: %s\n", errbuf);
        exit(1);
    }

    fprintf(stderr, "Packet capture started\n");
    while ((packet = pcap_next(handle, &header)) != NULL)
    {
        //do something with the captured packet
        printf("Packet captured :%d bytes\n", header.len);
    }
    fprintf(stderr, "Packet capture ended\n");

    pcap_close(handle);
    exit(0);
}