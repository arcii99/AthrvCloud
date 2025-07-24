//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet length: %d\n", header->len);
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    //open capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    //compile filter expression
    pcap_compile(handle, &fp, filter_exp, 0, net);

    //apply filter expression
    pcap_setfilter(handle, &fp);

    //capture packets
    pcap_loop(handle, 0, packet_handler, NULL);
    
    //close and cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;

}