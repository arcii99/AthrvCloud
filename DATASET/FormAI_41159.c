//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user_data, const struct pcap_pkthdr *pkthdr, const u_char *packet_data) {
    printf("Packet Captured!\n");
    printf("Packet length: %d\n", pkthdr->len);
    printf("Number of bytes: %d\n", pkthdr->caplen);
    printf("Timestamp: %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));
}

int main(int argc, char **argv) {
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    printf("Capturing on device: %s\n", dev);
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (!handle) {
        printf("Failed to open device: %s\n", errbuf);
        return 1;
    }
    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("Device %s doesn't provide Ethernet headers - not supported\n", dev);
        return 1;
    }
    pcap_loop(handle, 0, packet_handler, NULL);
    pcap_close(handle);
    return 0;
}