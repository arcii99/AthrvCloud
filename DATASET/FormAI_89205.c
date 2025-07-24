//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv)
{
    char *device = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packets = 0;

    // Open device for sniffing
    handle = pcap_open_live(device, 65535, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        exit(1);
    }

    // Start sniffing and print packet details
    printf("Starting packet monitor on device %s...\n", device);
    while (1) {
        struct pcap_pkthdr header;
        const u_char *packet;

        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet #%d:\n", ++packets);
            printf(" - Length: %d bytes\n", header.len);
            printf(" - Source MAC: ");
            for (int i=0; i < 6; i++) {
                printf("%02x", packet[i]);
                if (i < 5) printf(":");
            }
            printf("\n");
            printf(" - Destination MAC: ");
            for (int i=6; i < 12; i++) {
                printf("%02x", packet[i]);
                if (i < 11) printf(":");
            }
            printf("\n");
        }
    }

    // Close handle and exit
    pcap_close(handle);
    return 0;
}