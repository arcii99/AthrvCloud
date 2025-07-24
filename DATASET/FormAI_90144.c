//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
// Are you ready to experience the thrill of network packet monitoring?
// This program will have you on the edge of your seat!

#include <stdio.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE]; // Allocate space for error buffer
    pcap_t *handle; // Handler for the capture session
    struct bpf_program fp; // Apply filter
    char filter_exp[] = "port 80"; // Filter expression
    bpf_u_int32 mask; // Netmask of our sniffing device
    bpf_u_int32 net; // IP of our sniffing device
    struct pcap_pkthdr header; // The header that pcap gives us
    const u_char *packet; // The actual packet
    
    // Let's begin the packet monitoring
    printf("Initializing packet monitoring...\n");
    
    // Define our device for sniffing
    char *device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", device);
    
    // Get netmask and IP of device
    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        printf("Error getting netmask and IP: %s\n", errbuf);
        net = 0;
        mask = 0;
    }
    printf("IP: %u.%u.%u.%u\n", (net >> 24) & 0xff, (net >> 16) & 0xff, (net >> 8) & 0xff, net & 0xff);
    printf("Netmask: %u.%u.%u.%u\n", (mask >> 24) & 0xff, (mask >> 16) & 0xff, (mask >> 8) & 0xff, mask & 0xff);
    
    // Create a handle for the capture session
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device for packet capture: %s\n", errbuf);
        return 1;
    }
    printf("Successfully opened handle for capture session!\n");
    
    // Set our filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Could not parse filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // Apply the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Could not apply filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // Begin the packet capturing process
    printf("Starting packet capture...\n");
    while (1) {
        packet = pcap_next(handle, &header);
        printf("Packet capture successful! Length = %d\n", header.len);
        // Do more cool things with the packet here!
    }
    
    // Close the capture session
    pcap_close(handle);
    printf("Capture session closed. Goodbye!\n");
    return 0;
}