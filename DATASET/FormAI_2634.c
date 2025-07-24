//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pcap.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    char *dev;
    char filter_exp[] = "tcp";
    struct in_addr addr;

    // Retrieve device name
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return -1;
    }

    // Get network mask and address
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    addr.s_addr = net;
    printf("Device: %s\n", dev);
    printf("Net: %s\n", inet_ntoa(addr));
    addr.s_addr = mask;
    printf("Mask: %s\n", inet_ntoa(addr));

    // Open device for live capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return -1;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, mask) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    // Apply filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    // Begin packet processing loop
    pcap_loop(handle, -1, process_packet, NULL);

    // Close device
    pcap_close(handle);
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Unused parameters
    (void) args;

    printf("Packet length: %d\n", header->len);
    printf("Number of bytes captured: %d\n", header->caplen);
    printf("Timestamp: %ld.%06ld seconds\n", (long)header->ts.tv_sec, (long)header->ts.tv_usec);
}