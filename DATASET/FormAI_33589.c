//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Hello! I captured a packet!\n");
    printf("Packet Length: %d\n", pkthdr->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open device eth0: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    printf("Packet Capturer is Ready! Let's capture some Packets!\n");

    pcap_loop(handle, 0, packetHandler, NULL);

    pcap_close(handle);
    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}