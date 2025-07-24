//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char const *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "icmp";
    bpf_u_int32 subnet_mask, ip;

    // open pcap session, return pointer to session
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening pcap: %s\n", errbuf);
        return 1;
    }

    // get network mask and address
    if (pcap_lookupnet("eth0", &ip, &subnet_mask, errbuf) == -1) {
        fprintf(stderr, "Error looking up network: %s\n", errbuf);
        return 1;
    }

    // compile filter expression and apply filter
    if (pcap_compile(handle, &filter, filter_exp, 0, subnet_mask) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error applying filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // loop through incoming packets and call packet_handler for each packet
    pcap_loop(handle, -1, packet_handler, NULL);

    // clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}


// function called for each packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet, length=%d\n", header->len);
    // process packet here
}