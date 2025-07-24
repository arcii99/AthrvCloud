//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    const u_char *packet;

    // Get default device name and network
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for capturing packets
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't compile filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    printf("Listening on %s...\n", dev);
    while (1) {
        packet = pcap_next(handle, &header);
        printf("Got a packet of length %d\n", header.len);
        // Do something with the captured packet here...
    }

    // Close device and free allocated resources
    pcap_close(handle);
    pcap_freecode(&fp);

    return 0;
}