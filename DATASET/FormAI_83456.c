//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *hdr, const u_char *pkt){
    printf("Packet captured. Length: %d\n", hdr->len);

    // Add code to analyze packet data here
    
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open network interface for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open interface eth0: %s\n", errbuf);
        return 1;
    }

    printf("Packet capture started on interface eth0...\n");

    // Start packet capture loop
    if (pcap_loop(handle, 0, packet_handler, NULL) < 0) {
        fprintf(stderr, "Error in pcap loop: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Cleanup
    pcap_close(handle);

    return 0;
}