//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: calm
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *user_data, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data) 
{
    // Do something with each incoming packet
}

int main(int argc, char **argv) 
{
    char dev[] = "en0"; // Set the network interface to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE]; // Buffer to hold error messages
    
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf); // Open the network interface
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }
    
    const u_char *packet; // Buffer to hold data of incoming packets
    
    struct pcap_pkthdr packet_header; // Information about each packet
    
    int ret = pcap_next_ex(handle, &packet_header, &packet); // Get the next packet
    
    if (ret == 1) {
        // If a packet was successfully captured:
        printf("Packet received with length: %d\n", packet_header.len);
        packet_handler(NULL, &packet_header, packet);
    } else if (ret == 0) {
        // Timeout elapsed
        printf("Timeout elapsed, no packet was captured\n");
    } else if (ret == -1) {
        // An error occurred
        printf("An error occurred while capturing a packet: %s\n", pcap_geterr(handle));
    }
    
    pcap_close(handle); // Close the network interface
    
    return 0;
}