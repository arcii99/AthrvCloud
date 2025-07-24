//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data);

int main(void){

    pcap_t *handle;
    char interface[] = "wlan0";
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_expression[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;
    int num_packets = 10;

    // open interface for packet capture
    handle = pcap_open_live(interface, BUFSIZ, 0, 1000, error_buffer);

    // get subnet mask and ip address of the interface
    pcap_lookupnet(interface, &ip, &subnet_mask, error_buffer);

    // compile and apply filter for tcp traffic on port 80
    pcap_compile(handle, &filter, filter_expression, 0, ip);
    pcap_setfilter(handle, &filter);

    // capture packets and call packet_handler for each packet
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // close capture handle
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data){

    printf("Packet Captured\n");

    // check if packet is TCP
    if(pkt_data[12] == 0x08 && pkt_data[13] == 0x00 && pkt_data[23] == 0x06){

        printf("TCP Packet Captured\n");

        // get source and destination ports
        int src_port = (pkt_data[34] << 8) + pkt_data[35];
        int dst_port = (pkt_data[36] << 8) + pkt_data[37];

        // print source and destination ports
        printf("Source Port: %d\n", src_port);
        printf("Destination Port: %d\n", dst_port);
    }
}