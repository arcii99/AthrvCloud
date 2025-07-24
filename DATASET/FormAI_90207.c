//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: mind-bending
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured!\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for holding any errors
    pcap_t *handle; // Handle for capturing packets

    // Open a live capture handle on the first available network interface
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture handle: %s\n", errbuf);
        return 1;
    }

    // Start capturing packets and pass them to our packet handler function
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the capture handle when we are done
    pcap_close(handle);

    return 0;
}