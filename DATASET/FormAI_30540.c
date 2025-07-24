//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {

    printf("Packet captured with length of %d bytes.\n", header->len);
}

int main(int argc, char **argv) {

    char* device = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t* handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error opening device %s: %s\n", device, errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("Device %s does not provide Ethernet headers - not supported\n", device);
        return 1;
    }

    printf("Listening on device: %s\n", device);

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}