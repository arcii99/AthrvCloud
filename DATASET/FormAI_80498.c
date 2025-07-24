//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: enthusiastic
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    int snapshot_length = 1024;
    int promiscuous = 1;
    int timeout = 1000;

    char *device = pcap_lookupdev(error_buffer);
    if(device == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }

    handle = pcap_open_live(device, snapshot_length, promiscuous, timeout, error_buffer);
    if(handle == NULL) {
        printf("Error opening device %s: %s\n", device, error_buffer);
        return 1;
    }

    if(pcap_loop(handle, -1, packet_handler, NULL) < 0) {
        printf("Error while capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 0;

    printf("Packet %d:\n", ++count);
    printf("%d bytes captured\n", header->caplen);
    printf("%d bytes total\n", header->len);

    // Do something with the packet data here!
}