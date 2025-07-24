//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: inquisitive
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *hdr, const u_char *packet) {
    printf("Packet captured\n");
    // Add your packet processing code here
}

int main(int argc, char **argv) {
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Open the device for live capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    // Get the network number and mask associated with the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}