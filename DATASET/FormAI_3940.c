//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);
void print_packet_info(const u_char *, int);

int main(int argc, char *argv[]) {
    char *devname;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 net, mask;
    struct bpf_program fp;
    char filter_exp[] = "type mgt subtype probe-req";
    struct pcap_pkthdr header;
    const u_char *packet;

    // get default device name
    devname = pcap_lookupdev(errbuf);
    if (devname == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // open device for sniffing
    handle = pcap_open_live(devname, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", devname, errbuf);
        return EXIT_FAILURE;
    }

    // get network and mask
    if (pcap_lookupnet(devname, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", devname, errbuf);
        net = 0;
        mask = 0;
    }

    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set the filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // start sniffing
    pcap_loop(handle, -1, process_packet, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return EXIT_SUCCESS;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int size = header->len;
    print_packet_info(packet, size);
}

void print_packet_info(const u_char *packet, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%.2x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}