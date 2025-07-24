//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: relaxed
#include <stdio.h> 
#include <pcap.h> 
     
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) 
{ 
    printf("Packet Captured!\n"); 
} 
     
int main() 
{ 
    pcap_t *handle; 
    char error_buffer[PCAP_ERRBUF_SIZE]; 
    struct bpf_program filter; 
    char filter_expression[] = "tcp"; 
    bpf_u_int32 subnet_mask, ip; 
     
    // Find the default network device with pcap_lookupdev()
    char *device = pcap_lookupdev(error_buffer); 
    if(device == NULL) { 
        printf("Error finding device: %s\n", error_buffer); 
        return 1; 
    } 
     
    // Get network mask and IP address information for the network device using pcap_lookupnet()
    if(pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1) { 
        printf("Error getting network information: %s\n", error_buffer); 
        ip = 0; 
        subnet_mask = 0; 
    } 
     
    // Open the network device for packet capture with pcap_open_live()
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer); 
    if(handle == NULL) { 
        printf("Error opening device: %s\n", error_buffer); 
        return 1; 
    } 
     
    // Compile the filter expression with pcap_compile()
    if(pcap_compile(handle, &filter, filter_expression, 0, ip) == -1) { 
        printf("Error compiling filter: %s\n", pcap_geterr(handle)); 
        return 1; 
    } 
     
    // Apply the compiled filter to the network device with pcap_setfilter()
    if(pcap_setfilter(handle, &filter) == -1) { 
        printf("Error setting filter: %s\n", pcap_geterr(handle)); 
        return 1; 
    } 
     
    pcap_loop(handle, -1, process_packet, NULL); 
     
    return 0; 
}