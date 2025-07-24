//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){

    int *counter = (int *) args;
    printf("Packet number: %d\n", ++(*counter));
    printf("Packet size: %d bytes\n", header->len);

    /* Printing out the packet in hexadecimal form */
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main(){

    pcap_t *handle;             /* Session handle */
    char errbuf[PCAP_ERRBUF_SIZE];      /* Error string */
    struct bpf_program fp;          /* The compiled filter expression */
    char filter_exp[] = "port 80";      /* The filter expression */
    bpf_u_int32 net;                /* The IP address of our sniffing device */
    bpf_u_int32 mask;               /* The netmask of our sniffing device */
    struct pcap_pkthdr header;          /* The header that pcap gives us */
    const u_char *packet;           /* The actual packet */

    /* Get device information */
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    /* Get netmask of the sniffing device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open the device for sniffing */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* Compile and apply the filter expression */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* Intializing packet counter */
    int packet_count = 0;

    /* Capture packets */
    pcap_loop(handle, 0, packet_handler, (u_char *) &packet_count);

    /* Clean up */
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Capture finished, Captured %d packets\n", packet_count);

    return 0;
}