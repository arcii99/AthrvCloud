//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv) {
    char *device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout = 1000; // ms
    int num_packets = 10; // capture 10 packets

    // Find a network device to capture from
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding network device: %s\n", errbuf);
        return 1;
    }

    // Open the device for capturing
    handle = pcap_open_live(device, BUFSIZ, 0, timeout, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening network device: %s\n", errbuf);
        return 1;
    }
    printf("Capturing on device %s...\n", device);

    // Start capturing packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Close the capture device and clean up
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    // Print packet length and timestamp
    printf("Captured packet of length %d at %s", pkthdr->len, ctime((const time_t *)&pkthdr->ts.tv_sec));

    // Analyze the packet here
    // ...
}