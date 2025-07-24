//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Capturing packet...\n");
    // Add your packet handling logic here
}

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;

    // Find a suitable network interface to capture on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("pcap_lookupdev() failed: %s\n", errbuf);
        return 1;
    }

    // Open the interface for capturing
    pcap_handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (pcap_handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    struct bpf_program filter;
    char *filter_exp = "tcp port 80";
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("pcap_compile() failed: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }

    // Set the filter expression
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        printf("pcap_setfilter() failed: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }

    // Start capturing packets
    if (pcap_loop(pcap_handle, -1, got_packet, NULL) == -1) {
        printf("pcap_loop() failed: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(pcap_handle);

    return 0;
}