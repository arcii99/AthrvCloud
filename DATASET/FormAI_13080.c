//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

int main(int argc, char* argv[]) {
    char errbuff[PCAP_ERRBUF_SIZE];
    pcap_t* pcap_handle;
    struct pcap_pkthdr header;
    const u_char* pkt_data;
    int timeout_limit_ms = 1000;
    int retval;
    
    /* Open the network interface */
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 0, timeout_limit_ms, errbuff);
    
    /* Check if there was an error opening the interface */
    if (pcap_handle == NULL) {
        printf("Error: %s\n", errbuff);
        return 1;
    }
    
    /* Run the packet capture loop */
    retval = pcap_loop(pcap_handle, 0, packet_handler, NULL);
    
    /* Check if there was an error during the capture loop */
    if (retval == -1) {
        printf("Error during capture: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }
    
    /* Close the network interface */
    pcap_close(pcap_handle);
    
    return 0;
}

void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data) {
    /* Print out some info about the packet */
    printf("Received packet of size %d.\n", header->len);
    
    /* TODO: Analyze the packet */
    if (pkt_data[0] == 'H' && pkt_data[1] == 'A' && pkt_data[2] == 'P' && pkt_data[3] == 'P' && pkt_data[4] == 'Y') {
        printf("Received a happy packet! :)\n");
    }
}