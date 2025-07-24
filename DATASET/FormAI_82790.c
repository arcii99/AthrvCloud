//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h>

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    struct ether_header *eth_header;
    eth_header = (struct ether_header*) packet;

    // Check if the packet is an IP packet
    if(ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        printf("This is an IP Packet!\n");
    }
}

int main(){
    char *network_interface_name = "eth0";
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *network_interface;

    network_interface = pcap_open_live(network_interface_name, BUFSIZ, 0, -1, error_buffer);

    if (network_interface == NULL){
        printf("Error Opening Interface: %s\n", error_buffer);
        return 1;
    }

    pcap_loop(network_interface, 0, packetHandler, NULL);

    return 0;
}