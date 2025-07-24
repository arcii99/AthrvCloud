//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include <stdio.h>
#include <pcap.h>

int main() {
    printf("Welcome to the happy packet monitor!\n");
    printf("We're going to keep an eye on all those packets zipping around the network!\n");

    // set up a packet capture handle
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    // check for errors
    if (handle == NULL) {
        printf("Oops, looks like we couldn't open the capture handle: %s\n", errbuf);
        return 1;
    }

    // start the capture loop
    struct pcap_pkthdr* header;
    const u_char* packet;
    while (pcap_next_ex(handle, &header, &packet) == 1) {
        // yay, we caught a packet!
        printf("Woohoo! We got a packet!\n");

        // do some analysis (or just celebrate)
        // ...

        // print out the packet info
        printf("Capture length: %d\n", header->caplen);
        printf("Packet length: %d\n", header->len);
        printf("Payload:\n");
        for (int i = 0; i < header->caplen; i++) {
            printf("%02X ", *(packet + i));
        }
        printf("\n");
    }

    // close the capture handle and say goodbye
    pcap_close(handle);
    printf("Thanks for monitoring packets with us! Keep smiling and have a great day!\n");
    return 0;
}