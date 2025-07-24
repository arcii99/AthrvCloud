//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <pcap.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    unsigned char *packet;
    struct pcap_pkthdr header;
    int packet_count = 0;

    // open live capture device
    if ((handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return 1;
    }

    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // capture packets and print them out
    while (packet_count < 10) {
        packet_count++;
        printf("Packet %d:\n", packet_count);
        packet = (unsigned char *) pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error reading packet: %s\n", errbuf);
            continue;
        }
        printf("Packet length: %d bytes\n", header.len);
    }

    // clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Capture complete.\n");

    return 0;
}