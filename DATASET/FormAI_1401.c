//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

// Structure to hold packet data
struct packet_data {
    struct ethhdr eth_header; // Ethernet header
    unsigned char *packet_payload; // Packet payload
    int payload_size; // Payload size
};

// Function to print packet information
void print_packet_info(struct packet_data *packet) {
    printf("Source MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            packet->eth_header.h_source[0], packet->eth_header.h_source[1], packet->eth_header.h_source[2],
            packet->eth_header.h_source[3], packet->eth_header.h_source[4], packet->eth_header.h_source[5]);

    printf("Destination MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            packet->eth_header.h_dest[0], packet->eth_header.h_dest[1], packet->eth_header.h_dest[2],
            packet->eth_header.h_dest[3], packet->eth_header.h_dest[4], packet->eth_header.h_dest[5]);

    printf("Packet Payload: ");
    for(int i = 0; i < packet->payload_size; i++) {
        printf("%02X ", packet->packet_payload[i]);
    }
    printf("\n\n");
}

// Callback function to handle captured packets
void packet_handler(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet) {
    struct packet_data *packet_data_ptr, packet_data;
    packet_data_ptr = &packet_data;

    packet_data_ptr->eth_header = *(struct ethhdr *) packet;
    packet_data_ptr->packet_payload = (unsigned char *) packet + sizeof(struct ethhdr);
    packet_data_ptr->payload_size = header->len - sizeof(struct ethhdr);

    print_packet_info(packet_data_ptr);
}

int main(int argc, char **argv) {
    char *device; // Network interface device name
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    pcap_t *handle; // Handle for pcap library functions
    struct bpf_program fp; // Filter expression to use
    char filter_exp[] = "tcp"; // Filter expression to use
    bpf_u_int32 net; // IP address of our device
    bpf_u_int32 mask; // Subnet mask of our device

    // Get the name of the default device to use
    device = pcap_lookupdev(error_buffer);
    if(device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", error_buffer);
        return(1);
    }
    printf("Device: %s\n", device);

    // Get the network address and subnet mask for the device
    if(pcap_lookupnet(device, &net, &mask, error_buffer) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", device, error_buffer);
        net = 0;
        mask = 0;
    }
    printf("Network address: %d.%d.%d.%d\n", (net & 0xFF), ((net >> 8) & 0xFF), ((net >> 16) & 0xFF), ((net >> 24) & 0xFF));
    printf("Subnet mask: %d.%d.%d.%d\n", (mask & 0xFF), ((mask >> 8) & 0xFF), ((mask >> 16) & 0xFF), ((mask >> 24) & 0xFF));

    // Open the device for packet capture
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, error_buffer);
        return(1);
    }

    // Compile and apply the filter expression
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }

    // Start capturing packets and call the packet_handler function for each one
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the capture handle
    pcap_close(handle);

    return(0);
}