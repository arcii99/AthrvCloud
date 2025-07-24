//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // do packet analysis here...
    printf("Packet captured! Length: %d\n", header->len);
}

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // get network information
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        printf("Error: pcap_lookupnet - %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // open interface for capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: pcap_open_live - %s\n", errbuf);
        return 1;
    }

    // compile filter expression
    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        printf("Error: pcap_compile - %s\n", pcap_geterr(handle));
        return 1;
    }

    // apply filter
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error: pcap_setfilter - %s\n", pcap_geterr(handle));
        return 1;
    }

    // start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}