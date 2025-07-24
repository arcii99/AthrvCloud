//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header,const u_char *packet)
{
    printf("Got a packet \n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;

    // Open network interface for packet capture
    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Get network IP and netmask
    if (pcap_lookupnet("en0", &net, NULL, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device: %s\n", errbuf);
        net = 0;
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Start capturing packets using the callback function
    pcap_loop(handle, -1, got_packet, NULL);

    // Close and free memory allocated for the pcap handle
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}