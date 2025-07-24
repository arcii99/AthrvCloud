//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1;
    printf("Packet %d\n", count);
    printf("Capture Length: %d\n", pkthdr->caplen);
    printf("Packet Length: %d\n", pkthdr->len);
    count++;
}

int main(int argc, char** argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("Error: Only Ethernet packets are supported\n");
        exit(1);
    }

    pcap_loop(handle, -1, packetHandler, NULL);

    pcap_close(handle);
    return 0;
}