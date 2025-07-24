//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Donald Knuth
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *packet_header, const u_char *packet_data);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 netmask;
    struct pcap_pkthdr header;
    const u_char *packet;
    
    // Open the network interface for sniffing
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return -1;
    }
    
    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, netmask) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }
    
    // Set the filter for the pcap handler
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;        
    }
    
    // Start sniffing packets
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }
        packet_handler(NULL, &header, packet);
    }
    
    // Close the pcap handler
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *packet_header, const u_char *packet_data) {
    printf("Got a packet!\n");
    
    // Process the packet data here
}