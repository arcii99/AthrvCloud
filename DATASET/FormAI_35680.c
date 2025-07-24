//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <pcap.h>

// Define constants
#define BUFFER_SIZE 1024
#define TIMEOUT_MS 1000

int main(int argc, char* argv[]) {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Check for argument specifying the interface
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Open the interface for packet capture
    handle = pcap_open_live(argv[1], BUFFER_SIZE, 0, TIMEOUT_MS, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open interface %s: %s\n", argv[1], errbuf);
        return 1;
    }

    // Create a header struct to store packet metadata
    struct pcap_pkthdr header;
    const u_char *packet;

    // Continuously capture packets and print their data
    while (pcap_next_ex(handle, &header, &packet) == 1) {
        printf("Packet received! Length: %d\n", header.len);
        for (int i = 0; i < header.len; ++i) {
            printf("%02X ", *(packet + i));
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n\n");
    }

    // Close the packet capture interface when finished
    pcap_close(handle);

    return 0;
}