//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: dynamic
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *packet_header, const u_char *packet_data) {
    // Print out the packet's data
    printf("Packet captured! Length=%d\n", packet_header->len);
    for(int i=0; i < packet_header->len; i++) {
        printf("%02x ", packet_data[i]);
        if((i+1)%16==0) printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Find the default network device
    char *dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        fprintf(stderr, "Could not find default device: %s", errbuf);
        return 1;
    }

    // Get the network address and mask for the device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Could not get netmask for device %s: %s", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s", dev, errbuf);
        return 1;
    }

    // Compile and apply the filter
    if(pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter: %s", pcap_geterr(handle));
        return 1;
    }
    if(pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Could not apply filter: %s", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Listening on device %s...\n", dev);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}