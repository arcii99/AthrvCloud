//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Packet Captured!\n");
}

int main(int argc, char** argv)
{
    char* dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr = NULL;
    struct bpf_program filter;
    char filter_exp[] = "icmp";
    bpf_u_int32 net = 0, mask = 0;
    int retCode = 0;

    // Find a suitable device to capture packets on
    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        printf("%s\n", errbuf);
        return 1;
    }

    // Get network and mask properties for device
    retCode = pcap_lookupnet(dev, &net, &mask, errbuf);

    if (retCode == -1) {
        printf("%s\n", errbuf);
        return 1;
    }

    // Open pcap session
    descr = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);

    if (descr == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    retCode = pcap_compile(descr, &filter, filter_exp, 0, mask);

    if (retCode == -1) {
        printf("pcap_compile() failed: %s\n", pcap_geterr(descr));
        return 1;
    }

    // Apply filter expression
    retCode = pcap_setfilter(descr, &filter);

    if (retCode == -1) {
        printf("pcap_setfilter() failed: %s\n", pcap_geterr(descr));
        return 1;
    }

    // Capture packets
    pcap_loop(descr, -1, packetHandler, NULL);

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(descr);

    return 0;
}