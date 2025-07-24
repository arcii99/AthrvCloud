//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char **argv) {
    char *device = NULL;
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program bpf_filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    // Get the default network device if one was not specified
    if (argc > 1) {
        device = argv[1];
    } else {
        device = pcap_lookupdev(error_buffer);
        if (device == NULL) {
            printf("Error finding default network device: %s\n", error_buffer);
            exit(1);
        }
    }

    // Print out the device name
    printf("Device: %s\n", device);

    // Get the network IP and subnet mask
    if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1) {
        printf("Error finding IP and subnet mask for device: %s\n", error_buffer);
        exit(1);
    }

    // Open the network device for packet capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Error opening network device for packet capture: %s\n", error_buffer);
        exit(1);
    }

    // Compile and set the BPF filter expression
    if (pcap_compile(handle, &bpf_filter, filter_exp, 0, ip) == -1) {
        printf("Error compiling BPF filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &bpf_filter) == -1) {
        printf("Error setting BPF filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start the packet capture loop
    printf("Starting packet capture...\n");
    pcap_loop(handle, -1, process_packet, NULL);

    // Clean up and close the handle
    pcap_freecode(&bpf_filter);
    pcap_close(handle);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    printf("Packet captured!\n");

    // Print out the packet header fields
    printf("Timestamp: %s", ctime((const time_t*)&header->ts.tv_sec));
    printf("Length: %d bytes\n", header->len);
    printf("Cap Length: %d bytes\n", header->caplen);

    // Print out the packet data in hex format
    int i;
    for (i = 0; i < header->caplen; ++i) {
        printf("%02x ", buffer[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    fflush(stdout);
}