//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: sophisticated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [pcap_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open pcap file */
    handle = pcap_open_offline(argv[1], errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open pcap file '%s': %s\n", argv[1], errbuf);
        exit(EXIT_FAILURE);
    }

    /* Get network and mask */
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device '%s': %s\n", argv[1], errbuf);
        exit(EXIT_FAILURE);
    }

    /* Compile the filter expression */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter '%s': %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Apply the compiled filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter '%s': %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Start packet processing loop */
    pcap_loop(handle, 0, packet_handler, NULL);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    /* TODO: Implement packet processing logic here */
}