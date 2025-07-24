//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char *packet){
    // Get packet length
    int packetLength = pkthdr->len;

    // Extract ethernet header
    struct ether_header* ethernetHeader = (struct ether_header*)packet;

    // Extract protocol
    short protocol = ntohs(ethernetHeader->ether_type);

    // Determine protocol type
    char protocolStr[16];
    if (protocol == ETHERTYPE_IP){
        sprintf(protocolStr, "IP");
    } else if (protocol == ETHERTYPE_ARP){
        sprintf(protocolStr, "ARP");
    } else {
        sprintf(protocolStr, "Unknown");
    }

    // Print packet information to console
    printf("\n-----------------------\n");
    printf("Packet Length: %d\n", packetLength);
    printf("Protocol: %s\n", protocolStr);
}

int main(int argc, char **argv){
    // Check for filename argument
    if (argc < 2){
        printf("Please specify a filename.\n");
        exit(1);
    }

    // Open file with libpcap
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* pcap = pcap_open_offline(argv[1], errbuf);
    if (pcap == NULL){
        printf("Error opening file: %s\n", errbuf);
        exit(1);
    }

    // Start packet capture
    int result = pcap_loop(pcap, 0, packet_handler, NULL);
    if (result == -1){
        printf("Error capturing packets: %s\n", pcap_geterr(pcap));
        exit(1);
    }

    // Close file and exit program
    pcap_close(pcap);
    return 0;
}