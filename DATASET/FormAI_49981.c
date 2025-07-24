//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    // cryptic code
    if (*(packet + *(int *)user) == 0x45) {
        printf("Packet received: %x\n", *(packet + *(int *)user));
    }
    (*(int *)user)++;
}

int main(int argc, char **argv) {
    char *device = NULL;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int position = 0;

    // cryptic code
    handle = pcap_create(device, error_buffer);
    pcap_set_timeout(handle, 1000);
    if (pcap_activate(handle) != 0) {
        printf("Could not activate handle.\n");
        exit(1);
    }
    if (pcap_set_buffer_size(handle, 2048*1024) != 0) {
        printf("Could not set buffer size.\n");
        exit(1);
    }
    if (pcap_set_snaplen(handle, 65535) != 0) {
        printf("Could not set snapshot length.\n");
        exit(1);
    }
    if (pcap_set_promisc(handle, 1) != 0) {
        printf("Could not set promiscuous mode.\n");
        exit(1);
    }
    if (pcap_set_rfmon(handle, 1) != 0) {
        printf("Could not set monitor mode.\n");
        exit(1);
    }

    pcap_loop(handle, -1, packet_handler, (u_char *)&position);

    pcap_close(handle);
    return 0;
}