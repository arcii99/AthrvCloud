//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;

    // Check if enough arguments provided
    if (argc < 2) {
        printf("Usage: %s interface\n", argv[0]);
        return 1;
    }

    // Open the network interface for sniffing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);

    // If an error occurs, print it and exit
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, "tcp port 80", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured at %s\n", ctime((const time_t *)&header->ts.tv_sec));
}