//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main()
{  
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("en0", BUFSIZ, 1, 1000, error_buffer);

    // Check if interface was opened correctly
    if (handle == NULL) {
        printf("Couldn't open device: %s\n", error_buffer);
        return 1;
    }

    // Compile filter expression
    struct bpf_program filter;
    const char *filter_exp = "port 80"; // Only capture HTTP traffic
    bpf_u_int32 net_mask;   // Network mask of the capture device
    bpf_u_int32 net_ip;     // IP address of the capture device

    if (pcap_lookupnet("en0", &net_ip, &net_mask, error_buffer) == -1) {
        printf("Couldn't get netmask for en0: %s\n", error_buffer);
        net_ip = 0;
        net_mask = 0;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, net_mask) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        pcap_freecode(&filter);
        return 1;
    }

    // Start packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup and close
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}

// Callback function to process the packets
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    // Print packet content
    printf("Packet length: %d\n", header->len);
    for (int i=0; i < header->len; i++) {
        printf("%02x ", pkt_data[i]);
        if (i % 16 == 15 || i == header->len - 1) printf("\n");
    }
}