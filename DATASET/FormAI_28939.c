//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdio.h>
#include <pcap.h>

// Function to handle captured packets
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured with length %d\n", header->len);
    // Code to handle the captured packets
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    int capture_time = 10; // Time to capture packets (in seconds)
    
    printf("Welcome to my unique C Packet Capturer!\n");
    
    // Find a suitable network interface for capturing packets
    char *interface = pcap_lookupdev(error_buffer);
    if (interface == NULL)
    {
        printf("Error finding network interface: %s\n", error_buffer);
        return 1;
    }
    printf("Using network interface %s\n", interface);
    
    // Open the network interface for packet capturing
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        printf("Error opening network interface for packet capturing: %s\n", error_buffer);
        return 1;
    }
    
    // Set a filter for capturing only TCP packets
    struct bpf_program filter;
    char filter_expression[] = "tcp";
    if (pcap_compile(handle, &filter, filter_expression, 0, 0) == -1)
    {
        printf("Error compiling packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error setting packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    printf("Starting packet capture...\n");
    
    // Begin capturing packets
    pcap_loop(handle, -1, handle_packet, NULL);
    
    pcap_freecode(&filter); // Free the memory assigned to the filter
    pcap_close(handle); // Close the handle to the network interface
    
    printf("Packet capture completed!\n");
    
    return 0;
}