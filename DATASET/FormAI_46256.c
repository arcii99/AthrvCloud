//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header,
        const u_char *packet)
{
    printf("Packet Captured!\n");
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open network interface for live capture
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Failed to open device eth0: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Starting packet capture...\n");

    // Start packet capture loop
    if (pcap_loop(handle, 0, got_packet, NULL) < 0) {
        fprintf(stderr, "Error in pcap_loop(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Close the handle
    pcap_close(handle);

    return EXIT_SUCCESS;
}