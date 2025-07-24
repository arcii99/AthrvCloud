//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Callback function called by pcap_loop for each captured packet */
void packet_handler(u_char* arg, const struct pcap_pkthdr* pkt_header, const u_char* pkt_data) {
    printf("Packet captured!\n");
}

int main(int argc, char** argv) {
    char *dev;  /* The device to sniff on */
    char errbuf[PCAP_ERRBUF_SIZE];  /* Error string */
    pcap_t* handle;  /* Session handle */
    bpf_u_int32 subnet_mask;  /* Subnet mask */
    bpf_u_int32 ip;  /* The IP of our sniffing device */
    struct bpf_program filter;  /* Compiled filter expression */

    /* Define the device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Find the subnet mask and IP of the device */
    if (pcap_lookupnet(dev, &ip, &subnet_mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        ip = 0;
        subnet_mask = 0;
    }

    /* Open the capture session */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    /* Compile and apply the filter expression */
    if (pcap_compile(handle, &filter, "type mgt subtype probe-req", 1, subnet_mask) == -1) {
        fprintf(stderr, "Couldn't compile filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't apply filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Start capturing packets */
    if (pcap_loop(handle, 0, packet_handler, NULL) == -1) {
        fprintf(stderr, "Couldn't start packet capture: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Clean up */
    pcap_freecode(&filter);
    pcap_close(handle);
    printf("Capture complete.\n");
    return EXIT_SUCCESS;
}