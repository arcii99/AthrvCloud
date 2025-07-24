//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: light-weight
#include <stdio.h>
#include <pcap.h>

int main(int argc, char const *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer to store pcap errors
    pcap_t* descr;
    const unsigned char* packet;
    struct pcap_pkthdr header; // header struct to store packet details

    descr = pcap_open_live("enp0s3", BUFSIZ, 0, -1, errbuf); // open live interface - here enp0s3

    if (descr == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", "enp0s3", errbuf); // print error message if device is not opened
        return 1;
    }

    packet = pcap_next(descr, &header); // read packet from device
    printf("Packet Length: %d\n", header.len); // print packet length

    int i;
    for (i = 0; i < header.len; i++) {
        printf("%02x ", packet[i]); // print packet in hex format
    }

    printf("\n");

    return 0; // end program
}