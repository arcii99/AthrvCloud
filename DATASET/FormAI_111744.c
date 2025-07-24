//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured!\n");
    for(int i=0;i<header->len;i++){
        printf("%02x ", pkt_data[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handler;
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    int num_packets = 10;

    // Find a suitable device to capture packets on
    char *dev = pcap_lookupdev(errbuf);
    if(dev == NULL){
        fprintf(stderr, "Failed to find suitable device: %s\n", errbuf);
        return 1;
    }
    printf("Using device: %s\n", dev);

    // Get network information and mask for device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
        fprintf(stderr, "Failed to get network information: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Open the device for capturing
    handler = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handler == NULL){
        fprintf(stderr, "Failed to open device: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if(pcap_compile(handler, &fp, filter_exp, 0, net) == -1){
        fprintf(stderr, "Failed to compile filter expression: %s\n", pcap_geterr(handler));
        pcap_close(handler);
        return 1;
    }

    // Apply the filter expression to the device
    if(pcap_setfilter(handler, &fp) == -1){
        fprintf(stderr, "Failed to apply filter expression: %s\n", pcap_geterr(handler));
        pcap_close(handler);
        return 1;
    }

    // Start capturing packets
    printf("Capturing packets...\n");
    pcap_loop(handler, num_packets, packet_handler, NULL);

    // Close the device
    pcap_close(handler);
    return 0;
}