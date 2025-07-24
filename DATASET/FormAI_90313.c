//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* This function is called for each network packet */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    /* Do whatever you want with the packet here */
    printf("Received a packet of length %d\n", header->len);
}

int main(int argc, char **argv)
{
    char *device;           // Name of the network device to monitor
    char error_buffer[PCAP_ERRBUF_SIZE];    // Buffer for storing error messages
    pcap_t *handle;         // Handle for monitoring the network device
    struct bpf_program filter;      // Filter expression
    char filter_string[] = "tcp and dst port 80";     // Filter expression string

    /* Retrieve the name of the network device to monitor */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Failed to find available network device: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    /* Open the network device for monitoring */
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open network device for monitoring: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    /* Compile the filter expression */
    if (pcap_compile(handle, &filter, filter_string, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Failed to compile filter expression: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Apply the filter expression */
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Failed to apply filter expression: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Start the packet capture loop */
    if (pcap_loop(handle, -1, packet_handler, NULL) == -1) {
        fprintf(stderr, "Failed to start packet capture loop: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Close the network device handle */
    pcap_close(handle);

    return EXIT_SUCCESS;
}