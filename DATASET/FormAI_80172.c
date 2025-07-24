//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Define maximum packet size */
#define SNAP_LEN 65535

/* Function to handle captured packets */
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured!\n");
    // You can also perform additional processing on the packet here
}

int main(int argc, char *argv[]) {
    char *dev = NULL; /* The device to capture on */
    char errbuf[PCAP_ERRBUF_SIZE]; /* Error string buffer */
    pcap_t *handle = NULL; /* Session handle */
    struct bpf_program fp; /* Filter program */
    bpf_u_int32 mask; /* netmask of the sniffing device */
    bpf_u_int32 net; /* ip of the sniffing device */
    int num_packets = 0; /* Number of packets to capture */

    /* Retrieve the device to sniff on */
    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        fprintf(stderr, "Could not find a device to capture on: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Open the capture device */
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        fprintf(stderr, "Failed to compile filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to apply filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Retrieve the network and netmask information of the sniffing device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Failed to get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Start capturing packets indefinitely */
    pcap_loop(handle, num_packets, handle_packet, NULL);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Finished capturing packets");

    return 0;
}