//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Callback function to process captured packets */
void process_packet(u_char *arg, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    static int packet_count = 0;
    printf("Packet %d:\n", ++packet_count);
    printf("Length: %d\n", pkthdr->len);

    /* Access packet data here; packet points to the start of the packet */
}

int main(int argc, char **argv) {
    char *dev; /* Name of the device to capture packets from */
    char error_buf[PCAP_ERRBUF_SIZE]; /* Buffer to hold error messages */
    pcap_t *handle; /* Handle for pcap functions */
    int snap_len = 65535; /* Maximum packet size to capture */
    int timeout = 1000; /* Time to wait for packets in milliseconds */

    /* Look up the default device to capture packets from if none is specified */
    if(argc == 1) {
        dev = pcap_lookupdev(error_buf);
        if(dev == NULL) {
            fprintf(stderr, "Error finding default device: %s\n", error_buf);
            exit(EXIT_FAILURE);
        }
    } else {
        dev = argv[1];
    }

    /* Open the device for capturing */
    handle = pcap_open_live(dev, snap_len, 1, timeout, error_buf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", dev, error_buf);
        exit(EXIT_FAILURE);
    }

    printf("Capturing packets on device %s...\n", dev);

    /* Set a callback function to process each captured packet */
    pcap_loop(handle, -1, process_packet, NULL);

    /* Clean up and exit */
    pcap_close(handle);
    return 0;
}