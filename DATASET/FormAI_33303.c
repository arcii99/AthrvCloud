//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* callback function to process captured packets */
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured!\n");

    /* process packet here */
}

int main(int argc, char *argv[]) {
    char *dev; /* device to capture on */
    char errbuf[PCAP_ERRBUF_SIZE]; /* buffer to store error messages */
    pcap_t *handle; /* pcap handle for packet capture */

    /* get default device if none specified */
    if(argc < 2) {
        dev = pcap_lookupdev(errbuf);
        if(dev == NULL) {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            return(EXIT_FAILURE);
        }
    }
    else {
        dev = argv[1];
    }

    printf("Capturing on device: %s\n", dev);

    /* open device for packet capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(EXIT_FAILURE);
    }

    /* set filter for packet capture */
    struct bpf_program fp; /* compiled filter program */
    char filter_exp[] = "port 80"; /* filter expression */
    bpf_u_int32 mask; /* subnet mask */
    bpf_u_int32 net; /* ip address */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(EXIT_FAILURE);
    }

    /* start packet capture */
    pcap_loop(handle, 0, process_packet, NULL);

    /* cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return(EXIT_SUCCESS);
}