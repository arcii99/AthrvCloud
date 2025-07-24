//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: relaxed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet);

int main(int argc, char **argv) {
    char *dev = NULL;                   // Name of the device to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE];      // Error buffer to store errors
    pcap_t *handle = NULL;              // Handle to the device
    
    // Use default device if none is provided
    if (argc < 2) {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            printf("Could not find default device: %s\n", errbuf);
            return 1;
        }
    } else {
        dev = argv[1];
    }
    
    // Open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }
    
    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // Cleanup
    pcap_close(handle);
    printf("Done\n");
    return 0;
}

// This function will be called for each captured packet
void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    uint16_t ether_type;
    uint16_t ip_protocol;
    const u_char *udp_pkt_data;
    int udp_pkt_len;
    struct tm *time;
    char timestr[16];
    
    // Convert packet timestamp to human-readable format
    time = localtime(&header->ts.tv_sec);
    strftime(timestr, sizeof(timestr), "%H:%M:%S", time);
    
    // Extract the EtherType field from the Ethernet header
    ether_type = (packet[12] << 8) | packet[13];
    
    if (ether_type == 0x0800) {    // IPv4 packet
        // Extract the IP protocol field from the IPv4 header
        ip_protocol = packet[23];
        
        if (ip_protocol == 0x11) {  // UDP packet
            // Extract the UDP packet data and length
            udp_pkt_data = packet + 42;
            udp_pkt_len = header->caplen - 42;
            
            // Print out the packet information
            printf("%s UDP packet:\n", timestr);
            printf(" Source IP: %d.%d.%d.%d\n", packet[26], packet[27], packet[28], packet[29]);
            printf(" Dest. IP: %d.%d.%d.%d\n", packet[30], packet[31], packet[32], packet[33]);
            printf(" Source port: %d\n", (udp_pkt_data[0] << 8) | udp_pkt_data[1]);
            printf(" Dest. port: %d\n", (udp_pkt_data[2] << 8) | udp_pkt_data[3]);
            printf(" Length: %d bytes\n", (udp_pkt_data[4] << 8) | udp_pkt_data[5]);
            printf(" Data: ");
            for (int i = 0; i < udp_pkt_len; i++) {
                printf("%02x ", udp_pkt_data[i]);
            }
            printf("\n");
        }
    }
}