//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void process_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* buffer);

int main(int argc, char* argv[]) {
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Check for capture device argument
    if (argc != 2) {
        fprintf(stderr, "Invalid arguments. Usage: %s [device]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get network information for device
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "pcap_lookupnet failed: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for live capture
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live failed: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Filter packets
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "pcap_compile failed: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter failed: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Start capturing packets
    pcap_loop(handle, -1, process_packet, NULL);

    // Close device
    pcap_close(handle);

    return EXIT_SUCCESS;
}

void process_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* buffer) {
    printf("Packet captured! Length: %d\n", header->len);
    // Process packet data here
}