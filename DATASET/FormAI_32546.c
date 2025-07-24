//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Sherlock Holmes
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

/* Define a struct for packet header */
struct PacketHeader {
    struct timeval ts;
    int caplen;
    int len;
};

/* Define a callback function for packet capturing */
void packet_callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct PacketHeader* packetHeader = (struct PacketHeader*) args;
    packetHeader->ts = header->ts;
    packetHeader->caplen = header->caplen;
    packetHeader->len = header->len;
    
    /* Print captured packet data */
    printf("Packet captured at: %s\n", ctime((const time_t*)&header->ts.tv_sec));
    printf("Captured packet length: %d\n", header->caplen);
    
    /* Parse and print packet data */
    for (int i = 0; i < header->caplen; ++i) {
        printf("%.2x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char **argv) {
    /* Initialize variables */
    char *device;
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct PacketHeader packetHeader;
    
    /* Get device name */
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", error_buffer);
        return EXIT_FAILURE;
    }
    printf("Device found: %s\n", device);
    
    /* Open device for packet capture */
    handle = pcap_open_live(device, 65536, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return EXIT_FAILURE;
    }
    printf("Device opened successfully for packet capture.\n");
    
    /* Start packet capturing */
    printf("Start capturing packets...\n");
    pcap_loop(handle, -1, packet_callback, (u_char*) &packetHeader);
    
    /* Close device */
    pcap_close(handle);
}