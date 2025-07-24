//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Donald Knuth
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    struct bpf_program fp;
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    
    /* Define the device */
    char *device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Could not find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", device);

    /* Find the properties for the device */
    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Could not get netmask for device %s: %s\n", device, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open the capture device */
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return(2);
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not apply filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* Capture and print packets */
    while (1) {
        packet = pcap_next(handle, &header);
        printf("Received packet with length %d\n", header.len);
        /* Add your processing logic here... */
    }

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return(0);
}