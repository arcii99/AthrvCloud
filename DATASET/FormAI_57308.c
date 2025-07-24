//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Define a callback function for pcap_loop() */
void process_packet(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_body)
{
    static int packet_count = 1;
    printf("Packet #%d\n", packet_count);
    printf("Packet size: %d bytes\n", packet_header->len);
    packet_count++;
}

int main()
{
    char *device; /* Device to sniff on */
    char error_buffer[PCAP_ERRBUF_SIZE]; /* Error buffer */
    pcap_t *handle; /* Session handle */
    int snapshot_length = 1024; /* Snapshot length to capture */
    int promiscuous = 0; /* Promiscuous mode */
    int timeout = 1000; /* Timeout in milliseconds */
    int packet_count = 10; /* Number of packets to capture */

    /* Find a suitable device */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Error finding device: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    } else {
        printf("Sniffing on device %s\n", device);
    }

    /* Open the device for sniffing */
    handle = pcap_open_live(device, snapshot_length, promiscuous, timeout, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, error_buffer);
        exit(EXIT_FAILURE);
    }

    /* Start sniffing with pcap_loop() */
    pcap_loop(handle, packet_count, process_packet, NULL);

    /* Close the session */
    pcap_close(handle);

    return 0;
}