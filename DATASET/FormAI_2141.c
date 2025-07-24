//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: energetic
#include <pcap.h> 

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    static int packet_count = 1;
    printf("Packet %d:\n", packet_count++);
    
    // Parse packet data (ethernet, IP, TCP/UDP etc.), print relevant info
    // Example: printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    
    // Open network device for capturing, and set filters (if any)
    pcap_t *handle = pcap_open_live("eth0", 65536, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }
    struct bpf_program fp; // Compiled filter expression (if any)
    char filter_exp[] = "tcp"; // Example filter (capture only TCP packets)
    bpf_u_int32 net;
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // Start capturing packets, calling packet_handler function for each packet
    // (or use pcap_dispatch to handle multiple packets at once)
    printf("Capturing packets...\n");
    pcap_loop(handle, 0, packet_handler, NULL); 
    
    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}