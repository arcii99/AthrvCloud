//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Romeo and Juliet
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n");
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *device;
    struct bpf_program fp;
    bpf_u_int32 netmask;
    bpf_u_int32 ip;
    int num_packets = 10;
    int timeout = 1000; /* In milliseconds */

    /* Find a suitable device to capture packets */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Couldn't find a suitable device: %s\n", error_buffer);
        return 2;
    }

    /* Open the device for packet capture */
    handle = pcap_open_live(device, BUFSIZ, 1, timeout, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, error_buffer);
        return 2;
    }

    /* Compile the filter */
    if (pcap_compile(handle, &fp, "tcp", 0, netmask) == -1) {
        fprintf(stderr, "Couldn't compile filter: %s\n", pcap_geterr(handle));
        return 2;
    }

    /* Set the filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set filter: %s\n", pcap_geterr(handle));
        return 2;
    }

    /* Capture packets */
    pcap_loop(handle, num_packets, got_packet, NULL);

    /* Close the handle */
    pcap_close(handle);

    return 0;
}