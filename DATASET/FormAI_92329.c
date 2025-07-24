//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: medieval
#include <stdio.h>
#include <pcap.h>

// Callback function that is called each time a packet is captured
void packet_handler(u_char *user_data, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
    // Print out the packet's header information
    printf("Packet captured: Length=%d\n", pkt_header->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the network interface for capturing
    handle = pcap_open_live("eth0", 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s", errbuf);
        return 1;
    }

    // Loop indefinitely and capture packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the capture handle
    pcap_close(handle);

    return 0;
}