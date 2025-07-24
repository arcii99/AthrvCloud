//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* buffer)
{   
    printf("Packet received\n");
    
    // Print packet timestamp
    time_t rawtime = header->ts.tv_sec;
    struct tm* time_info = localtime(&rawtime);
    printf("Timestamp: %s", asctime(time_info));
    
    // Print packet length
    printf("Packet length: %d bytes\n", header->len);
    
    // Print packet content
    for(int i=0; i<header->len; i++)
    {
        printf("%02x ", buffer[i]);           
        if((i+1)%16 == 0)
            printf("\n");
    }
    printf("\n==============================\n\n");
}

int main(int argc, char *argv[])
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t* pcap_handle;
    struct bpf_program fp;
    char filter_expression[] = "tcp port 80";  // Filter expression, only capture TCP packets on port 80
    
    // Check for command line arguments
    if(argc != 2)
    {
        printf("Usage: %s [interface]\n", argv[0]);
        return -1;
    }
    
    // Open the specified network interface for packet capture
    pcap_handle = pcap_open_live(argv[1], BUFSIZ, 0, -1, error_buffer);
    if(pcap_handle == NULL)
    {
        printf("Error: pcap_open_live() failed: %s\n", error_buffer);
        return -1;
    }
    
    // Compile the filter expression
    if(pcap_compile(pcap_handle, &fp, filter_expression, 0, PCAP_NETMASK_UNKNOWN) == -1)
    {
        printf("Error: pcap_compile() failed: %s\n", pcap_geterr(pcap_handle));
        pcap_close(pcap_handle);
        return -1;
    }
    
    // Apply the filter expression to the packet capture
    if(pcap_setfilter(pcap_handle, &fp) == -1)
    {
        printf("Error: pcap_setfilter() failed: %s\n", pcap_geterr(pcap_handle));
        pcap_close(pcap_handle);
        return -1;
    }
    
    // Start packet capture loop
    pcap_loop(pcap_handle, -1, packet_handler, NULL);
    
    // Close the packet capture handle
    pcap_close(pcap_handle);
    
    return 0;
}