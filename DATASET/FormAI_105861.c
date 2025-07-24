//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <pcap.h>

#define SNAP_LEN 65535

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet)
{
    // Print packet information
    printf("Packet length: %d\n", header->len);
}

int main(int argc, char* argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handler = pcap_open_live("eth0", SNAP_LEN, 1, 0, errbuf);

    if (handler == NULL) {
        printf("Error opening handler: %s\n", errbuf);
        return 1;
    }

    pcap_loop(handler, -1, packet_handler, NULL);

    pcap_close(handler);

    return 0;
}