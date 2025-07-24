//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <stdio.h>
#include <pcap.h>

int main(int argc, char* argv[]) {

    char* dev = argv[1]; // get the device name from command line arguments
    char errbuf[PCAP_ERRBUF_SIZE]; // buffer for error messages

    pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf); // open live capture on device
    if (handle == NULL) { // check if handle is valid
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    printf("Capturing on device %s...\n", dev);

    struct pcap_pkthdr* header; // packet header
    const u_char* packet; // actual packet

    while (pcap_next_ex(handle, &header, &packet) >= 0) { // capture loop
        printf("Packet capture successful!\n");
        printf("Packet length: %d\n", header->len); // print packet length
    }

    pcap_close(handle);
    return 0;
}