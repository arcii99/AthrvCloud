//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv)
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Check for valid command line arguments
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get network number and mask
    if(pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile the filter expression
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Apply the compiled filter
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured\n");
    printf("Length of packet: %d\n", header->len);
    printf("Time of capture: %s", ctime((const time_t *)&header->ts.tv_sec));
}