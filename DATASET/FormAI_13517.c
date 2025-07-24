//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net, mask;

    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Get network and mask information
    if (pcap_lookupnet(argv[1], &net, &mask, error_buffer) == -1) {
        printf("Error getting network and mask information: %s\n", error_buffer);
        return 2;
    }

    // Open the capture device
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Error opening capture device: %s\n", error_buffer);
        return 2;
    }

    // Compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error applying filter expression: %s\n", pcap_geterr(handle));
        return 2;
    }

    // Start capturing packets
    printf("Starting packet capture...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Packet capture complete.\n");
    return 0;
}

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    // Do something with the packet here...
    printf("Packet received with length %d\n", header->len);
}