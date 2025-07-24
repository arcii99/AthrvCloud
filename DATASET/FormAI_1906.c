//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>

/* callback function */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 0;

    /* print the received packet count */
    printf("Received Packet Count: %d\n", ++count);

    /* print the packet length */
    printf("Packet length: %d\n", header->len);

    /* print the packet */
    for (int i = 0; i < header->len; i++) {
        if (i % 16 == 0) printf("\n");
        printf("%.2x ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    pcap_t *handle;         /* handle for the session */
    char *dev;              /* name of the device */
    char errbuf[PCAP_ERRBUF_SIZE];  /* error buffer */
    struct bpf_program fp;      /* filter program */
    char filter_exp[] = "port 80";  /* filter expression */
    bpf_u_int32 mask;       /* subnet mask */
    bpf_u_int32 net;        /* ip */
    int num_packets = 10;   /* number of packets to capture */

    /* find a device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", dev);

    /* get network number and mask associated with capture device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* open capture device */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* compile the filter expression */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* apply the compiled filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* now we can set our callback function */
    pcap_loop(handle, num_packets, packet_handler, NULL);

    /* cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return(0);
}