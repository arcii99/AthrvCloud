//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    printf("Packet captured of length %d\n", header->len);
}

int main(int argc, char *argv[])
{
    char *devname;
    char errorbuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeoutms = 1000;

    // get the name of the first network interface the pcap library finds
    devname = pcap_lookupdev(errorbuffer);
    if (devname == NULL) {
        fprintf(stderr, "No network interfaces found: %s\n", errorbuffer);
        return 1;
    } else {
        printf("Using network interface: %s\n", devname);
    }

    // open the network interface for packet capturing
    handle = pcap_open_live(devname, BUFSIZ, 1, timeoutms, errorbuffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open network interface: %s\n", errorbuffer);
        return 1;
    }

    // set a callback function to be called for each captured packet
    if (pcap_loop(handle, 0, process_packet, NULL) < 0) {
        fprintf(stderr, "Error while capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}