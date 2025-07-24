//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(){
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_limit = 10000; // Timeout in milliseconds
    int promisc_mode = 1; // Set to 1 for promiscuous mode
    int buffer_size = 1024000; // Buffer size in bytes
    char *device = "eth0"; // Name of the network interface you want to monitor
    
    struct bpf_program filter; // Struct to hold the BPF filter information
    char filter_exp[] = "tcp"; // BPF filter expression
    
    // Open the network interface in promiscuous mode
    handle = pcap_open_live(device, buffer_size, promisc_mode, timeout_limit, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", error_buffer);
        return(1);
    }
    
    // Compile and apply the BPF filter
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error applying filter: %s\n", pcap_geterr(handle));
        return(1);
    }
    
    // Start the capture loop and pass the packet data to the packet_handler function
    pcap_loop(handle, -1, packet_handler, NULL);
    
    // Cleanup
    pcap_freecode(&filter);
    pcap_close(handle);
    
    return(0);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    // Print the packet data to the console
    printf("Packet received - length: %d\n", header->len);
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n\n");
}