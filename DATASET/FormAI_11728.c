//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured\n");
    printf("Packet length: %d\n", header->len);
    
    // Parse packet here
    
    printf("\n");
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    
    // Open network device
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 0, -1, errbuf);
    if (pcap_handle == NULL) {
        printf("Error: %s", errbuf);
        return 1;
    }
    
    // Set filter for HTTP traffic
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    if (pcap_compile(pcap_handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error: Could not compile filter expression");
        return 1;
    }
    if (pcap_setfilter(pcap_handle, &fp) == -1) {
        printf("Error: Could not set filter");
        return 1;
    }
    
    // Start capturing packets
    int num_packets = 10;
    pcap_loop(pcap_handle, num_packets, packet_handler, NULL);
    
    // Close network device
    pcap_close(pcap_handle);
    
    return 0;
}