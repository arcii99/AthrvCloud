//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char **argv)
{
    char *device = "eth0"; // default device
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int snapshot_length = 1024;
    int promiscuous = 0;
    int timeout = 1000;

    if (argc > 1) {
        device = argv[1];
    }

    handle = pcap_create(device, error_buffer);
    if (!handle) {
        printf("Error creating handle: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    if (pcap_set_snaplen(handle, snapshot_length) != 0) {
        printf("Error setting snapshot length: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_set_promisc(handle, promiscuous) != 0) {
        printf("Error setting promiscuous mode: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_set_timeout(handle, timeout) != 0) {
        printf("Error setting timeout: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_activate(handle) != 0) {
        printf("Error activating handle: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_close(handle);
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    printf("Packet captured with length %d\n", header->len);
}