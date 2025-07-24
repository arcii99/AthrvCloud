//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: paranoid
#include <stdio.h>
#include <pcap.h>
#include <netinet/in.h>

// Callback function for packet processing
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet handler called\n");
    // Check if packet is an IP packet
    if(pkt_data[12]==0x08 && pkt_data[13]==0x00) {
        printf("IP packet detected!\n");
        
        // Extract destination IP address
        struct in_addr dest_addr;
        memcpy(&dest_addr, &pkt_data[30], sizeof(dest_addr));
        char *dest_ip = inet_ntoa(dest_addr);
        printf("Destination IP address: %s\n", dest_ip);
        
        // Check if destination IP is suspicious
        if(strcmp(dest_ip, "127.0.0.1") == 0 || strcmp(dest_ip, "192.168.1.1") == 0) {
            printf("Suspicious destination IP detected!\n");
            
            // Extract source IP address
            struct in_addr src_addr;
            memcpy(&src_addr, &pkt_data[26], sizeof(src_addr));
            char *src_ip = inet_ntoa(src_addr);
            printf("Source IP address: %s\n", src_ip);
            
            // Check if source IP is also suspicious
            if(strcmp(src_ip, "127.0.0.1") == 0 || strcmp(src_ip, "192.168.1.1") == 0) {
                printf("Suspicious source IP detected!\n");
                
                // Extract destination port
                u_short dest_port = ntohs(*(u_short*)&pkt_data[36]);
                printf("Destination port: %d\n", dest_port);
                
                // Check if destination port is below 1024
                if(dest_port < 1024) {
                    printf("Destination port is below 1024! Possible exploit attempt detected.\n");
                }
            }
        }
    }
}

int main() {
    // Open the network interface for monitoring
    char err_buff[PCAP_ERRBUF_SIZE];
    pcap_t *descr = pcap_open_live("eth0", BUFSIZ, 1, 1, err_buff);
    
    // Apply a filter to capture only IP packets
    struct bpf_program filter;
    char *filter_exp = "ip";
    bpf_u_int32 netmask;
    if(pcap_compile(descr, &filter, filter_exp, 0, netmask) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(descr));
        return 1;
    }
    if(pcap_setfilter(descr, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(descr));
        return 1;
    }
    
    // Start capturing packets and processing them
    int num_packets = 10;
    pcap_loop(descr, num_packets, packet_handler, NULL);
    
    // Close the network interface
    pcap_close(descr);
    
    return 0;
}