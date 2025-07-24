//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {

    char errbuf[PCAP_ERRBUF_SIZE];

    // Open device for capturing packets
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Set filter for capturing only TCP packets
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets indefinitely
    printf("Starting packet capture...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close device
    pcap_close(handle);

    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    static int count = 0;

    // Print packet information
    printf("Packet %d:\n", ++count);
    printf("    Length: %d\n", header->len);
    printf("    Time: %s", ctime((time_t *)&header->ts.tv_sec));

    // Print packet contents
    printf("Packet Contents:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02x", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
        else if ((i + 1) % 8 == 0) printf("  ");
        else printf(" ");
    }
    if (header->len % 16 != 0) printf("\n");

    printf("--------------------\n");

    return;
}