//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Function to handle a captured packet */
void pkt_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured! Length: %d\n", header->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_ms = 1000; // Timeout in milliseconds
    int num_packets = 10; // Number of packets to capture

    /* Open the device for capturing */
    handle = pcap_open_live("en0", BUFSIZ, 1, timeout_ms, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open device: %s\n", errbuf);
        return 1;
    }

    /* Compile the filter expression */
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Failed to compile filter expression\n");
        return 1;
    }

    /* Set the filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to set filter\n");
        return 1;
    }

    /* Start capturing packets */
    pcap_loop(handle, num_packets, pkt_handler, NULL);

    /* Close the device */
    pcap_close(handle);

    return 0;
}