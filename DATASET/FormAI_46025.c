//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
    printf("Packet length: %d\n", packet_header.len);
}

void handle_packet(u_char *user, const struct pcap_pkthdr *packet_header, const u_char *packet) {
    print_packet_info(packet, *packet_header);
}

int main(int argc, char **argv) {

    char *device = argv[1];
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int snapshot_length = 1024;
    int timeout_limit = 10000;
    int promiscuous_mode = 1;
    int buffer_size = 10 * 1024 * 1024;

    handle = pcap_open_live(device, snapshot_length, promiscuous_mode, timeout_limit, error_buffer);

    if (handle == NULL) {
        printf("Could not open device %s: %s\n", device, error_buffer);
        return 1;
    }

    pcap_set_buffer_size(handle, buffer_size);

    pcap_loop(handle, -1, handle_packet, NULL);

    pcap_close(handle);

    return 0;
}