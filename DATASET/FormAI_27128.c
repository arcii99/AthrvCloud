//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h> 
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

/* Define the packet callback function */
void packet_callback(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    
    static int packet_count = 0;    /* number of packets processed */
    
    /* Get the Ethernet header */
    struct ether_header *ethernet_header = (struct ether_header *)packet;
    
    /* Check if the packet is IP */
    if (ntohs(ethernet_header->ether_type) == ETHERTYPE_IP) {
        
        /* Get the IP header */
        struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ether_header));
        
        /* Check if the IP protocol is TCP */
        if (ip_header->protocol == IPPROTO_TCP) {
        
            /* Get the TCP header */
            struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
            
            /* Get the source and destination ports */
            uint16_t src_port = ntohs(tcp_header->source);
            uint16_t dst_port = ntohs(tcp_header->dest);
            
            /* Print the source and destination ports */
            printf("Packet #%d Source Port: %d, Destination Port: %d\n", packet_count, src_port, dst_port);
            
            /* Increment the packet count */
            packet_count++;
        }
    }
}

int main(int argc, char **argv) {
    
    char *device;                   /* Name of the device to sniff */
    char error_buffer[PCAP_ERRBUF_SIZE];    /* Error buffer for pcap functions */
    pcap_t *handle;                 /* pcap handle */
    int packet_count_limit = 10;    /* number of packets to process */
    int timeout_limit = 10000;      /* time limit in milliseconds */
    
    /* Get the name of the device to sniff */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        return 1;
    }
    
    /* Open the device for sniffing */
    handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        return 1;
    }
    
    /* Start capturing */
    pcap_loop(handle, packet_count_limit, packet_callback, NULL);
    
    /* Close the handle */
    pcap_close(handle);
    
    return 0;
}