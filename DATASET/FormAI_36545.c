//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: minimalist
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

void print_hex(const u_char *payload, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%02X ", payload[i]);
        if ((i % 16 == 15) || (i == len - 1)) {
            int j;
            for (j = 0; j < 15 - (i % 16); j++) {
                printf("   ");
            }
            printf("| ");
            for (j = (i - (i % 16)); j <= i; j++) {
                if (isprint(payload[j])) {
                    printf("%c", payload[j]);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured, length = %d\n", header->len);
    print_hex(packet, header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        printf("Failed to find a usable device: %s\n", errbuf);
        exit(1);
    } else {
        printf("Using device: %s\n", dev);
    }

    pcap_t *handle;
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Failed to open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Failed to get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Failed to compile filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Failed to set filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}