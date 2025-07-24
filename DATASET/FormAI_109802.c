//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Function to be executed each time a packet is captured */
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    printf("---- Packet Captured ----\n");

    /* Parse the packet header */
    printf("Packet Length: %d bytes\n", header->len);
    printf("Captured Time: %s", ctime((const time_t *)&header->ts.tv_sec));

    /* Parse the packet contents */
    int i, j = 0;
    for (i = 0; i < header->len; i++) {
        printf("%02x ", buffer[i]);
        if (++j == 16) { /* Print 16 bytes per line */
            printf("\n");
            j = 0;
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = NULL;
    const u_char *packet;
    struct pcap_pkthdr header;

    /* Find the default network device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Failed to find default network device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Open the network device for packet capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open network device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Packet Monitoring Program in Retro Style\n");
    printf("Listening on device: %s\n", dev);

    /* Capture packets until the program is interrupted */
    pcap_loop(handle, -1, process_packet, NULL);

    /* Cleanup */
    pcap_close(handle);
    printf("Program Terminated.\n");

    return EXIT_SUCCESS;
}