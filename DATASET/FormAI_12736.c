//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Sherlock Holmes
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 0, 1000, error_buffer);

    if (handle == NULL) {
        printf("Error: %s\n", error_buffer);
        return 1;
    }

    int result = pcap_loop(handle, -1, packet_handler, NULL);

    if (result == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured\n");
    // Do something with the packet data
}