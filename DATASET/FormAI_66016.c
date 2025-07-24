//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet arrived at: %s", ctime((const time_t *)&header->ts.tv_sec));
}

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "udp port 53";
    bpf_u_int32 net;

    // Open network device
    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Compile and apply filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Capture packets
    printf("Listening for packets...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}