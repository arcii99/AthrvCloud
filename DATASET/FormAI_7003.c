//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv)
{
    char *dev = NULL;                            /* The device to use */
    pcap_t *handle = NULL;                       /* Session handle */
    char errbuf[PCAP_ERRBUF_SIZE];                /* Error string */
    struct bpf_program fp;                        /* The compiled filter */
    char filter_exp[] = "tcp port 80";            /* The filter expression */
    bpf_u_int32 mask;                             /* Our netmask */
    bpf_u_int32 net;                              /* Our IP */

    /* Define the device, or use the default */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Using device: %s\n", dev);

    /* Find the properties for the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* Register callback function for processing packets */
    if (pcap_loop(handle, -1, packet_handler, NULL) == -1) {
        fprintf(stderr, "Couldn't start capture: %s\n", pcap_geterr(handle));
        return(2);
    }

    /* Clean up and exit */
    pcap_freecode(&fp);
    pcap_close(handle);
    return(0);
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    /* Process packet here */
    printf("Packet captured with timestamp: %ld.%06ld\n", pkthdr->ts.tv_sec, pkthdr->ts.tv_usec);
}