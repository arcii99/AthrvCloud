//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

#define PROMISCUOUS_MODE 1
#define READ_PACKET_TIMEOUT 1000

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured.\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net, mask;

    // Find a suitable network interface to listen on
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Failed to find a suitable network interface: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Get the network and mask of the chosen interface
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Failed to get network and mask information: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Open the network interface in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, PROMISCUOUS_MODE, READ_PACKET_TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open network interface: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Failed to compile filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to apply filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Start capturing packets
    printf("Listening on device: %s\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}