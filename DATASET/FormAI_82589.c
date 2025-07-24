//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Look up network device
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev);

    // Get network device properties
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get network device properties: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Open network device for packet capturing, promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open network device: %s\n", errbuf);
        return 1;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't apply filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets indefinitely
    pcap_loop(handle, -1, packet_handler, NULL);

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured! Length: %d\n", header->len);
    // Process packet here
}