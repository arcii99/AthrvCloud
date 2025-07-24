//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *packet_header, const u_char *packet_data)
{
    // Process captured packet
    printf("Packet captured!\n");
}

int main(int argc, char **argv)
{
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_limit = 10000; // milliseconds
    
    // Get default device
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Error finding default device: %s\n", error_buffer);
        exit(1);
    }
    
    // Open device for capturing packets
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, error_buffer);
        exit(1);
    }
    
    // Capture packets
    if (pcap_loop(handle, -1, packet_handler, NULL) < 0) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
        exit(1);
    }
    
    // Close device
    pcap_close(handle);
    
    return 0;
}