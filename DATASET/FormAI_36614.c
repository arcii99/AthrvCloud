//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <pcap.h>

#define SNAP_LEN 1518

void packet_handler(u_char *unused, const struct pcap_pkthdr *packet_header, const u_char *packet_data) {
    printf("Packet captured: %ld bytes\n", packet_header->len);
}

int main(int argc, char *argv[]) {
    char *device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    int timeout_limit = 10000;

    // Lookup a network device
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the device for packet capture
    pcap_handle = pcap_open_live(device, SNAP_LEN, 1, timeout_limit, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return 1;
    }

    // Start the capture
    printf("Capturing packets on device %s...\n", device);
    pcap_loop(pcap_handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(pcap_handle);
    printf("Done!\n");
    return 0;
}