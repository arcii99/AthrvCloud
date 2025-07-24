//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void capturePacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print Packet Length
    printf("Packet Length: %d\n", header->len);
    
    // Hex Dump of Packet Data
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packetCount = 0;

    // Open Network Device for Capturing
    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errorBuffer);
    if (handle == NULL) {
        printf("Error: %s\n", errorBuffer);
        exit(1);
    }

    // Start Capturing Packets
    pcap_loop(handle, 0, capturePacket, NULL);

    /* Stop capturing packets */
    pcap_close(handle);
    
    return 0;
}