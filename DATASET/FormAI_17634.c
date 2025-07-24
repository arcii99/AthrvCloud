//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

#define TCP_PROTOCOL 6
#define MAX_PACKET_LEN 65535

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];

    if(argc < 2) {
        printf("Error: Please provide an interface name\n");
        exit(1);
    }

    pcap_t *handle = pcap_open_live(argv[1], MAX_PACKET_LEN, 1, 1000, errbuf);

    if(!handle) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    while(1) {
        struct pcap_pkthdr header;
        const u_char *packet = pcap_next(handle, &header);

        if(!packet)
            continue;

        if(packet[23] == TCP_PROTOCOL) {
            printf("TCP Packet Captured!\n");
            // Do something with the captured TCP packets
        }
    }

    pcap_close(handle);
    return 0;
}