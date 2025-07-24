//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
#include <stdio.h>
#include <pcap.h> // include pcap library

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE]; // buffer that pcap functions use to store error messages
    pcap_t *handle; // pcap data link handler
    char filter_exp[] = "icmp"; // capture only ICMP packets
    struct bpf_program fp; // compiled filter expression
    bpf_u_int32 mask; // subnet mask
    bpf_u_int32 net; // IP
    int num_of_packets = 10; // number of packets to capture

    // get IP and subnet mask from current device
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        printf("pcap_lookupnet() failed: %s\n", errbuf);
        return 1;
    }

    // open device for capture
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    // compile and apply filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("pcap_compile() failed: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("pcap_setfilter() failed: %s\n", pcap_geterr(handle));
        return 1;
    }

    // capture packets
    pcap_loop(handle, num_of_packets, packet_handler, NULL);

    // close capture device
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    // print captured packet info
    printf("Packet length: %d\n", header->len);
    printf("Number of bytes: %d\n", header->caplen);
    printf("Timestamp: %s\n\n", ctime((const time_t *)&header->ts.tv_sec));
}