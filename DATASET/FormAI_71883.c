//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
// C Packet Capturer using pcap library
#include <stdio.h>
#include <pcap.h>

void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *packet_header,
    const u_char *packet_body
) {
    printf("Got a packet with length of [%d]\n", packet_header->len);
    printf("Payload:\n");
    for(int i=0; i < packet_header->len; i++) {
        printf("%02X ", *(packet_body + i));
        if ( (i + 1) % 16 == 0 ) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {

    char *device = "eth0";
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int snapshot_length = 1024;
    int total_packet_count = 10;
    u_char *my_arguments = NULL;

    handle = pcap_open_live(device, snapshot_length, 0, 1000, error_buffer);
    if ( handle == NULL ) {
        fprintf(stderr, "Could not open device %s: %s\n", device, error_buffer);
        return 2;
    }

    pcap_loop(handle, total_packet_count, my_packet_handler, my_arguments);

    pcap_close(handle);
    return 0;
}