//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

pcap_t *pcap_handle;
char error_buffer[PCAP_ERRBUF_SIZE];

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured! Length: %d\n", header->len);
    
    // Do whatever you want with the packet data here
}

int main(int argc, char *argv[])
{
    char *device = argv[1]; // Get the device name from command line
    
    // Open the network interface for packet capture
    pcap_handle = pcap_open_live(device, BUFSIZ, 0, 1000, error_buffer);
    if (pcap_handle == NULL) {
        printf("Error opening interface: %s\n", error_buffer);
        exit(1);
    }
    
    // Set a filter to capture only ICMP packets
    struct bpf_program filter;
    char filter_exp[] = "icmp";
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, 0) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    // Loop forever, capturing packets
    pcap_loop(pcap_handle, -1, capture_packet, NULL);
    
    // Close the packet capture interface
    pcap_close(pcap_handle);
    return 0;
}