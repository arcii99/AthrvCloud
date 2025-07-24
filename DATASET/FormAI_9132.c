//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *unused, const struct pcap_pkthdr *packet_header, const u_char *packet_body) {
    static int packet_count = 1;
    printf("\nPacket number %d:\n", packet_count);
    printf("\tPacket size: %d bytes\n", packet_header->len);
    printf("\tCapture time: %s\n", ctime((const time_t *) &packet_header->ts.tv_sec));
    printf("\tPacket contents:\n");

    for (u_int i = 0; i < packet_header->len; i++) {
        printf("%02x ", packet_body[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    packet_count++;
}

int main() {
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 5;
    int timeout_limit = 10000;

    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }

    printf("Sniffing from device: %s\n", device);

    handle = pcap_create(device, error_buffer);
    if (handle == NULL) {
        printf("Error creating handle: %s\n", error_buffer);
        return 1;
    }

    if (pcap_activate(handle) != 0) {
        printf("Error activating handle: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_set_snaplen(handle, 65535) != 0) {
        printf("Error setting snapshot length: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_set_promisc(handle, 1) != 0) {
        printf("Error setting promiscuous mode: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_set_timeout(handle, timeout_limit) != 0) {
        printf("Error setting timeout: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setnonblock(handle, 1, error_buffer) != 0) {
        printf("Error setting non-blocking mode: %s\n", error_buffer);
        return 1;
    }

    if (pcap_loop(handle, packet_count_limit, packet_handler, NULL) < 0) {
        printf("Error during loop: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}