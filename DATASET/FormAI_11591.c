//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: statistical
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

#define MAXBYTES2CAPTURE 2048

void processPacket(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("usage: %s <interface>\n", argv[0]);
        return 1;
    }

    char *device = argv[1];
    char errorBuffer[PCAP_ERRBUF_SIZE];

    pcap_t *handle;
    handle = pcap_open_live(device, MAXBYTES2CAPTURE, 1, 0, errorBuffer);

    if (handle == NULL) {
        printf("Unable to open %s: %s\n", device, errorBuffer);
        return 2;
    }

    printf("Monitoring %s...\n", device);

    pcap_loop(handle, -1, processPacket, NULL);

    pcap_close(handle);

    printf("Capture Complete!\n");

    return 0;
}

void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int ipHeaderLength = 0;
    int totalLength = 0;
    int tcpHeaderLength = 0;
    const u_char *IPHeader;
    const u_char *TCPHeader;
    const u_char *PacketData;

    /* get IP header from the packet */
    IPHeader = packet + 14;
    if (*IPHeader & 0xF0 == 0x40) {
        ipHeaderLength = (*IPHeader & 0x0F) * 4;
        /* get TCP header from the IP packet */
        TCPHeader = packet + 14 + ipHeaderLength;
        /* determine header length based on offset */
        tcpHeaderLength = (((*(TCPHeader + 12)) & 0xF0) >> 4) * 4;
        /* get packet data from the TCP packet */
        PacketData = packet + 14 + ipHeaderLength + tcpHeaderLength;
        /* determine total length of the packet */
        totalLength = ntohs(*((u_short *)(packet + 16)));
    }
    printf("Packet Captured: IP Header Length=%d, TCP Header Length=%d, Total Length=%d\n", ipHeaderLength, tcpHeaderLength, totalLength);
    return;
}