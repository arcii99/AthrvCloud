//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1;
    printf("Packet number %d:\n", count);
    printf("Length: %d bytes\n", header->len);
    count++;
}

int main(int argc, char **argv) {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get default network device if not provided by the user
    if (argc < 2) {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return EXIT_FAILURE;
        }
    }

    // Open network device for capturing
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply BPF filter to capture only TCP traffic
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get network address and netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        fprintf(stderr, "Couldn't compile BPF filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set BPF filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Start capturing network traffic
    printf("Starting packet capture on device %s...\n", dev);
    pcap_loop(handle, -1, got_packet, NULL);

    // Cleanup and exit
    pcap_freecode(&fp);
    pcap_close(handle);
    return EXIT_SUCCESS;
}