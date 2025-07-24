//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // This function will be called for each packet received by the sniffer
    printf("Received packet of length %d\n", header->len);
    
    // Add packet parsing logic here...
}

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get the network interface to sniff on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(1);
    }

    // Open the selected network interface for sniffing
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    // Compile the BPF filter program to only capture packets we're interested in
    if (pcap_compile(handle, &fp, "port 80", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "port 80", pcap_geterr(handle));
        exit(1);
    }

    // Apply the compiled BPF filter program to the sniffing session
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "port 80", pcap_geterr(handle));
        exit(1);
    }

    // Start the packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the sniffing session
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}