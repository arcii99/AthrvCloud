//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

/* Packet capture callback function */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) 
{
    printf("Packet captured with length %d\n", header->len);
}

int main(int argc, char **argv) 
{
    pcap_t *pcap_handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    /* Open pcap device for live capture */ 
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 0, 1000, errbuf);

    if (pcap_handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    printf("Listening on %s...\n", pcap_lookupdev(errbuf));

    /* Start capturing packets */
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    /* Clean up */
    pcap_close(pcap_handle);

    return 0;
}