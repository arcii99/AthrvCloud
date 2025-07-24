//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured\n");
}

int main(int argc, char **argv) {
    char *devname = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int snapshot_length = 1024;
    int promiscuous = 0;
    int timeout = 1000;

    // find device to capture packets from
    devname = pcap_lookupdev(error_buffer);
    if (devname == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }
    printf("Capturing from device %s\n", devname);

    // open device handle for capturing packets
    handle = pcap_open_live(devname, snapshot_length, promiscuous, timeout, error_buffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return 1;
    }

    // capture packets (unlimited)
    pcap_loop(handle, -1, packet_handler, NULL);

    // close device handle
    pcap_close(handle);

    return 0;
}