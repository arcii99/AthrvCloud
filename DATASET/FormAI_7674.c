//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: secure
#include <stdio.h>
#include <pcap.h>

// Maximum packet length to capture
#define MAX_PACKET_LENGTH 100

// Print error message and exit the program
void die(const char *error) {
    fprintf(stderr, "%s\n", error);
    exit(1);
}

// Process each packet
void processPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet length
    printf("Packet Length: %d\n", header->len);
    
    // Print packet content
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", *(packet + i));
    }
    printf("\n");
}

int main(int argc, char **argv) {
    char *device;               // Device to capture packets from
    pcap_t *handle;             // Handle to the device
    char errorBuffer[PCAP_ERRBUF_SIZE];     // Error buffer
    struct bpf_program filter;  // Packet filter
    char filterExpression[] = "ip";  // Filter expression
    bpf_u_int32 subnetMask, networkAddress;   // Subnet mask and network address

    // Get the default device name
    device = pcap_lookupdev(errorBuffer);
    if (device == NULL) {
        die("Unable to get device name");
    }

    // Open the device for capturing packets
    handle = pcap_open_live(device, MAX_PACKET_LENGTH, 1, 1000, errorBuffer);
    if (handle == NULL) {
        die("Unable to open device for capturing packets");
    }

    // Get the subnet mask and network address of the device
    if (pcap_lookupnet(device, &networkAddress, &subnetMask, errorBuffer) == -1) {
        die("Unable to get subnet mask and network address of the device");
    }

    // Compile filter expression
    if (pcap_compile(handle, &filter, filterExpression, 0, networkAddress) == -1) {
        die("Unable to compile filter expression");
    }

    // Apply filter to captured packets
    if (pcap_setfilter(handle, &filter) == -1) {
        die("Unable to apply filter to captured packets");
    }

    // Capture packets
    if (pcap_loop(handle, -1, processPacket, NULL) == -1) {
        die("Unable to capture packets");
    }

    // Close the handle to the device
    pcap_close(handle);

    return 0;
}