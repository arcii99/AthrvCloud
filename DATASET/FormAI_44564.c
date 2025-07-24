//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main()
{
    // Snap length (maximum bytes per packet to capture)
    int snapLen = 64;
    // Promiscuous mode (1 to sniff all traffic on network, 0 to sniff only traffic directed to this device)
    int promisc = 1;
    // Timeout (time to wait for packets in milliseconds)
    int timeout = 1000;
    // Error buffer
    char* errbuf[PCAP_ERRBUF_SIZE];
    // Interface to capture on
    char* iface = "eth0";

    // Open capture device
    pcap_t* pcapHandle = pcap_open_live(iface, snapLen, promisc, timeout, errbuf);
    if (pcapHandle == NULL) {
        fprintf(stderr, "Failed to open capture device: %s\n", errbuf);
        return -1;
    }

    // Set filter (capture only TCP packets)
    struct bpf_program filter;
    char* filterExp = "tcp";
    if (pcap_compile(pcapHandle, &filter, filterExp, 0, 0) == -1) {
        fprintf(stderr, "Failed to compile filter expression: %s\n", pcap_geterr(pcapHandle));
        return -1;
    }
    if (pcap_setfilter(pcapHandle, &filter) == -1) {
        fprintf(stderr, "Failed to set filter: %s\n", pcap_geterr(pcapHandle));
        return -1;
    }

    // Capture packets
    printf("Capturing packets on interface %s...\n", iface);
    pcap_loop(pcapHandle, -1, packet_handler, NULL);

    // Close capture device
    pcap_close(pcapHandle);

    return 0;
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // Parse packet
    int i = 0;
    printf("Packet:\n");
    for (i = 0; i < pkthdr->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}