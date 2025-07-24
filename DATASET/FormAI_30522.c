//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: systematic
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Open capture device
    handle = pcap_open_live("eth0", BUFSIZ, 0, -1, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        return 1;
    }

    // Get network and mask information
    if(pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Could not get network and mask information: %s\n", errbuf);
        return 1;
    }

    // Compile and apply filter expression
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not apply filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    // Print packet length
    printf("Packet length: %d\n", header->len);
}