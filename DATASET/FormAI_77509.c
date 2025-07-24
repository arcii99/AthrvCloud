//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535
#define PROMISC 1
#define TIMEOUT_MS 1000

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {

    char *dev_name, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask, net;
    int num_packets = 10;

    if (argc < 2) {
        printf("Usage: %s interface\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dev_name = argv[1];

    /* Get network number and mask for the device */
    if (pcap_lookupnet(dev_name, &net, &mask, errbuf) == -1) {
        printf("pcap_lookupnet() failed: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    /* Open device for capture */
    handle = pcap_open_live(dev_name, SNAP_LEN, PROMISC, TIMEOUT_MS, errbuf);
    if (handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Compile and apply filter */
    if (pcap_compile(handle, &fp, "icmp or tcp", 0, net) == -1) {
        printf("pcap_compile() failed: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("pcap_setfilter() failed: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    printf("Listening on %s... \n", dev_name);

    /* Capture packets */
    pcap_loop(handle, num_packets, packet_handler, NULL);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    static int count = 1;

    printf("Packet number %d:\n", count);
    printf("- Time Stamp: %d.%d\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("- Packet Length: %d\n", header->len);

    /* Packet content */
    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    count++;
}