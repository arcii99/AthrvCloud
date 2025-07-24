//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Alan Touring
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char error_buffer[PCAP_ERRBUF_SIZE]; // buffer to store error message
    pcap_t *handle; // pcap_t handle
    struct pcap_pkthdr header; // packet header
    const u_char *packet_data; // packet data
    
    // get name of interface to capture packets from
    char *interface = pcap_lookupdev(error_buffer);
    if (interface == NULL) {
        fprintf(stderr, "Error finding interface: %s\n", error_buffer);
        return 1;
    }
    
    // open the pcap capture handle
    handle = pcap_open_live(interface, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture handle: %s\n", error_buffer);
        return 1;
    }
    
    // capture a packet
    packet_data = pcap_next(handle, &header);
    if (packet_data == NULL) {
        fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // print the packet
    printf("Packet captured:\n");
    for (int i = 0; i < header.len; i++) {
        printf("%02x ", *(packet_data+i));
        if ((i+1) % 16 == 0) printf("\n");
    }
    printf("\n");
    
    // close the pcap handle
    pcap_close(handle);
    
    return 0;
}