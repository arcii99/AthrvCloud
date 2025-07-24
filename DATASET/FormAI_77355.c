//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    int byteCount = 0;
    int i;
    printf("Packet captured, size of packet = [%d]\n", pkthdr->len);
    for (i = 0; i < pkthdr->len; i++) {
        printf("%.2x ", packet[i]);
        byteCount++;

        if (byteCount == 16) {
            byteCount = 0;
            printf("\n");
        }
    }
    printf("\n\n");
}

int main() {
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr header;
    const u_char *packet;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Could not get mask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    printf("Packet monitoring started...\n");

    pcap_loop(handle, 0, packet_handler, NULL);

    printf("Packet monitoring stopped...\n");

    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}