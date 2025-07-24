//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char*, const struct pcap_pkthdr*, const u_char*);

int main(int argc, char **argv) {
    char *dev; // the device to capture on
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer
    pcap_t *handle; // session handle
    struct bpf_program fp; // compiled filter expression
    char filter_exp[] = "icmp"; // filter expression
    bpf_u_int32 net; // ip
    bpf_u_int32 mask; // netmask

    // find a capturing device if not specified
    if(argc > 1) {
        dev = argv[1];
    } else {
        dev = pcap_lookupdev(errbuf);
        if(dev == NULL) {
            fprintf(stderr, "Error finding default device: %s\n", errbuf);
            exit(EXIT_FAILURE);
        }
    }

    // get network mask and IP address of the device
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open the device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // compile and apply the filter expression
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // start the capturing loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 0;

    // print packet information
    printf("Packet %d:\n", ++count);
    printf("\tLength: %d\n", header->len);
    printf("\tCaptured Length: %d\n", header->caplen);
    printf("\tTime: %s", ctime((const time_t *)&header->ts.tv_sec));
}