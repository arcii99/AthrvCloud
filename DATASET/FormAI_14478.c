//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

int main(int argc, char *argv[])
{
    char *device; // The device to sniff on
    char error_buffer[PCAP_ERRBUF_SIZE]; // error buffer
    pcap_t *handle; // Session handle
    struct bpf_program filter; // The compiled filter expression
    char *filter_expression = "tcp"; // Our filter expression
    bpf_u_int32 subnet_mask, ip; // The subnet mask and IP of our device
    int number_of_packets = 10; // Number of packets to capture

    // Find a device to sniff on
    device = pcap_lookupdev(error_buffer);
    if(device == NULL)
    {
        printf("Error finding device: %s\n", error_buffer);
        return 1;
    }

    // Get the IP and subnet mask of the device
    if(pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1)
    {
        printf("Error getting IP and subnet mask: %s\n", error_buffer);
        ip = 0;
        subnet_mask = 0;
    }

    // Open the session in promiscuous mode
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if(handle == NULL)
    {
        printf("Error opening device %s: %s\n", device, error_buffer);
        return 1;
    }

    // Compile and apply the filter
    if(pcap_compile(handle, &filter, filter_expression, 0, ip) == -1)
    {
        printf("Error compiling filter expression: %s\n", error_buffer);
        return 1;
    }

    if(pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error setting filter expression: %s\n", error_buffer);
        return 1;
    }

    // Capture packets
    pcap_loop(handle, number_of_packets, print_packet_info, NULL);

    // Close the session
    pcap_close(handle);
    return 0;
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header)
{
    printf("Packet length: %d\n", packet_header.len);
    printf("Number of bytes captured: %d\n", packet_header.caplen);
    printf("Timestamp: %s", ctime((const time_t*)&packet_header.ts.tv_sec));
    printf("---------------------------------------------\n");

    // print packet content
    for(int i = 0; i < packet_header.caplen; i++)
    {
        printf("%02x ", *(packet+i));
        if((i+1) % 16 == 0)
            printf("\n");
    }
    printf("\n\n");
}