//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) 
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Get the name of the first device suitable for capture
    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Device: %s\n", dev);

    // Open the device for live capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Start capturing packets
    printf("Starting packet capture...\n");

    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);

    printf("Packet capture complete.\n");

    return EXIT_SUCCESS;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) 
{
    // Print the packet timestamp and length
    printf("\nPacket timestamp: %s", ctime((const time_t*)&header->ts.tv_sec));
    printf("Packet length: %d\n\n", header->len);

    // Print the packet in hexadecimal format
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", pkt_data[i]);

        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}