//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

#define SNAP_LEN 1518

void print_payload(const u_char *payload, int len);

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // open capture device
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // set filter to capture only TCP packets
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Could not parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // start capturing packets
    pcap_loop(handle, -1, got_packet, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Capture complete.\n");

    return 0;
}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int packet_count = 0;

    // print timestamp and packet length
    printf("%ld:%ld (%d)\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

    // print payload of the packet
    print_payload(packet, header->len);

    printf("\n\n");

    packet_count++;
}

void print_payload(const u_char *payload, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (i % 16 == 0) {
            printf(" ");
        }
        printf("%.2x ", payload[i]);
    }
    printf("\n");
}