//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <pcap.h>
#include <stdio.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Got a packet!\n");
}

int main(int argc, char **argv)
{
    char *device = argv[1]; /* first command line argument is the device name */
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int num_packets = 10;

    /* open device for live capture */
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", device, errbuf);
        return 2;
    }

    /* start the capture */
    pcap_loop(handle, num_packets, got_packet, NULL);

    /* stop the capture and close the device */
    pcap_close(handle);

    return 0;
}