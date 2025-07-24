//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // find the first available network interface
    char *dev = pcap_lookupdev(errbuf);

    // obtain the netmask for the interface
    pcap_lookupnet(dev, &net, &mask, errbuf);

    // open the interface for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    // compile and apply the filter to the interface
    pcap_compile(handle, &fp, filter_exp, 0, net);
    pcap_setfilter(handle, &fp);

    // start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {

    printf("Packet captured with length: %d\n", header->len);

    // process the packet data here...
}