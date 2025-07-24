//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

void packet_handler(u_char *user_parameter, const struct pcap_pkthdr *packet_header, const u_char *packet_body);

int main(int argc, char **argv) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *device = argv[1];
    int snapshot_length = 2048;
    int promiscuous = 0;
    int timeout_limit = 10000;
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 subnet_mask;
    bpf_u_int32 ip_address;

    if (pcap_lookupnet(device, &ip_address, &subnet_mask, error_buffer) == -1) {
    fprintf(stderr, "Could not get information for device: %s", device);
    ip_address = 0;
    subnet_mask = 0;
    }

    handle = pcap_open_live(device, snapshot_length, promiscuous, timeout_limit, error_buffer);
    if (handle == NULL) {
    fprintf(stderr, "Could not open device %s: %s\n", device, error_buffer);
    return 2;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, subnet_mask) == -1) {
    fprintf(stderr, "Bad filter - %s\n", pcap_geterr(handle));
    return 2;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Error setting filter - %s\n", pcap_geterr(handle));
    return 2;
    }
    pcap_loop(handle, -1, packet_handler, NULL);
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *user_parameter, const struct pcap_pkthdr *packet_header, const u_char *packet_body) {
    print_packet_info(packet_body, *packet_header);
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
    int i;
    int packet_length = packet_header.len;
    for (i = 0; i < packet_length; i++) {
    printf("%.2x ", packet[i]);
    if ((i + 1) % 16 == 0) {
        printf("\n");
    }
    }
    printf("\n\n");
}