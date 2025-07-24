//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv){

    // Defining variables for storing the device and error message
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    // Selecting the device to sniff packets on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    // Preparing the device for packet capture
    pcap_t *handle;
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    printf("Packet capture has started on device: %s\n", dev);

    // Looping over packets captured by the selected device
    int packet_count = 0;
    if (pcap_loop(handle, -1, packet_handler, (u_char *) &packet_count) == -1) {
        fprintf(stderr, "Error occured while processing packets: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return 2;
    }

    printf("Packet capture has stopped. Captured %d packets.\n", packet_count);

    // Closing the packet capture session and freeing up memory
    pcap_close(handle);
    return 0;
}

// Callback function which is called for each packet captured
void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    int *counter = (int *) user;

    printf("\nPacket %d:\n", ++(*counter));
    printf("    Timestamp: %s", ctime((const time_t *) &header->ts.tv_sec));
    printf("    Length: %d bytes\n", header->len);
    
    // Parsing the packet and printing its contents
    const u_char *ptr = packet;
    int i;
    printf("    Content: ");
    for (i = 0; i < header->len; i++) {
        printf("%02x ", ptr[i]);
        if ((i + 1) % 16 == 0)
            printf("\n            ");
    }
    printf("\n");
}