//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Alan Touring
#include <stdio.h>
#include <pcap.h>

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    /* Define the network interface */
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return -1;
    }

    /* Get network mask and IP */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open device for sniffing */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return -1;
    }

    /* Compile filter expression */
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    /* Apply compiled filter */
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    /* Sniff packets */
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            printf("No packet found.\n");
            continue;
        }
        printf("Packet length: %d\n", header.len);
    }

    /* Close handle */
    pcap_close(handle);
    return 0;
}