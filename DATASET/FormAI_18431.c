//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: peaceful
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(){
    char errbuf[PCAP_ERRBUF_SIZE];
    char *device;
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    int num_packets = 10;

    // Find a device to capture packets on
    device = pcap_lookupdev(errbuf);
    if(device == NULL) {
        printf("pcap_lookupdev() failed: %s\n", errbuf);
        exit(1);
    }

    // Open the device for capturing
    handle = pcap_open_live(device, BUFSIZ, 0, 1000, errbuf);
    if(handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    // Get the network and netmask of the device
    if(pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        printf("pcap_lookupnet() failed: %s\n", errbuf);
        exit(1);
    }

    // Compile a filter expression
    if(pcap_compile(handle, &fp, "icmp", 0, net) == -1) {
        printf("pcap_compile() failed\n");
        exit(1);
    }

    // Set the filter expression
    if(pcap_setfilter(handle, &fp) == -1) {
        printf("pcap_setfilter() failed\n");
        exit(1);
    }

    // Capture packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    // Decode the packet header
    printf("Packet length: %d\n", header->len);

    // Decode the packet
    printf("Packet data:\n");
    for(int i = 0; i < header->len; i++) {
        printf("%02x ", pkt_data[i]);
        if((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}