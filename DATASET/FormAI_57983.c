//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the device for capturing
    pcap_t *handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return 1;
    }

    // Set the filter
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Packet Capture started...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet Captured\n");

    // Print the packet header
    printf("Packet length: %d\n", header->len);

    // Print the packet payload
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}