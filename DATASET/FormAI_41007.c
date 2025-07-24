//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user_args, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data);

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 10;
    u_int timeout_limit = 10000;
    char dev[] = "wlo1"; // network device name, can be changed to your device name

    handle = pcap_open_live(dev, BUFSIZ, packet_count_limit, timeout_limit, error_buffer);

    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        exit(1);
    }

    pcap_loop(handle, packet_count_limit, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *user_args, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data) {
    printf("Packet Captured: Length = %d\n", pkt_header->len);
}