//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: real-life
/*
 * Wireless Network Scanner
 * 
 * This program scans for available wireless networks and displays the results.
 * It uses the libpcap library for capturing and analyzing network traffic.
 * 
 * Developed by: John Doe
 * Date: May 12, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SNAP_LEN 65535
#define PROMISC_MODE 1
#define TIMEOUT 1000

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[])
{
    char *interface;        // Interface name
    char filter_exp[] = "type mgt subtype beacon";   // Filter expression
    char errbuf[PCAP_ERRBUF_SIZE];      // Error string
    pcap_t *handle;         // Capture handle
    bpf_u_int32 net;        // IP address of our network
    bpf_u_int32 mask;       // Netmask of our network
    struct bpf_program fp;      // Compiled filter expression
    int num_packets = -1;      // Number of packets to capture, -1 for unlimited
    
    printf("Wireless Network Scanner -- press Ctrl+C to stop scanning\n");

    // Check for interface argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }
    else {
        interface = argv[1];
    }

    // Get network information for the specified interface
    if (pcap_lookupnet(interface, &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Error getting network information: %s\n", errbuf);
        return 1;
    }

    // Open the capture device
    handle = pcap_open_live(interface, SNAP_LEN, PROMISC_MODE, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return 1;
    }

    // Apply the filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter expression: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return 1;
    }
    
    // Start capturing packets
    pcap_loop(handle, num_packets, process_packet, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Scanning complete.\n");

    return 0;
}

// Callback function for processing packets
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    char ssid[32] = {0};
    const u_char *p;
    int offset, ssid_len;

    // Get the SSID from the packet
    p = packet + 36;
    offset = 0;
    while (*p != 0 && offset < 32) {
        ssid[offset] = *p++;
        offset++;
    }
    ssid_len = offset;

    // Convert the SSID to a printable string
    for (offset = 0; offset < ssid_len; offset++) {
        if (ssid[offset] < 32 || ssid[offset] > 126) {
            ssid[offset] = '.';
        }
    }

    // Print the network information
    printf("SSID: %s", ssid);
    printf("  BSSID: %02x:%02x:%02x:%02x:%02x:%02x", packet[10], packet[11], packet[12], packet[13], packet[14], packet[15]);
    printf("  Signal strength: %d dBm\n", (int)packet[22] - 256);

    return;
}