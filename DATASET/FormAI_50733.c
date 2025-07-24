//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: genious
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    printf("Packet Captured!\n");
}

int main(){
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error compiling filter expression. Exiting...\n");
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter. Exiting...\n");
        return 1;
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_close(handle);

    return 0;
}