//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Function to handle network packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured!\n");
}

int main(int argc, char *argv[]) {
    char *device; // Name of the network device
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *handle; // Packet capture handle

    // Get the name of the default network device
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("%s\n", error_buffer);
        return EXIT_FAILURE;
    }

    printf("Network device found: %s\n", device);

    // Open the network device for packet capture
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("%s\n", error_buffer);
        return EXIT_FAILURE;
    }

    printf("Network device opened for packet capture!\n");

    // Set filter expression for the capture
    struct bpf_program filter;
    char filter_expression[] = "port 80";
    if (pcap_compile(handle, &filter, filter_expression, 0, 0) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    printf("Filter set for port 80!\n");

    // Start capturing packets
    if (pcap_loop(handle, 0, packet_handler, NULL) == -1) {
        printf("Error capturing packets: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Close the network device
    pcap_close(handle);

    printf("Packet monitoring complete!\n");

    return EXIT_SUCCESS;
}