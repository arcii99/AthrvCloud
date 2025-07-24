//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE]; // buffer to hold error message

    // open a network capture interface
    pcap_t *handle;
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return 1;
    }

    // capture packets continuously
    printf("Listening for packets...\n");
    int num_packets = 0;
    while (num_packets < 10) {
        struct pcap_pkthdr header; // packet header information
        const u_char *packet; // packet data
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue; // no packet available, try again
        }
        printf("Received packet with length %d\n", header.len);
        num_packets++;
    }

    // close the network capture interface
    pcap_close(handle);
    return 0;
}