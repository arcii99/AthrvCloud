//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured!\n");
    // Do something with the captured packet here
}

int main(int argc, char *argv[]) {
    char *dev = argv[1];
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    const u_char *packet;
    struct pcap_pkthdr header;
    int num_packets = atoi(argv[2]);

    printf("Starting packet capture on %s... Capturing %d packets.\n", dev, num_packets);

    // Open device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Capture packets
    pcap_loop(handle, num_packets, capture_packet, NULL);

    // Close device and cleanup
    pcap_close(handle);

    printf("Packet capture complete.\n");
    return EXIT_SUCCESS;
}