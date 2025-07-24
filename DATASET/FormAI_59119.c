//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <pcap.h>
#include <time.h>
#include <stdlib.h>

/* callback function used by pcap_loop */
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    /* print packet timestamp */
    printf("Packet Timestamp: %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));

    /* get packet length */
    int packetLength = pkthdr->len;
    printf("Packet Length : %d bytes\n", packetLength);

    /* print raw packet data */
    printf("Raw Packet Data:\n");
    for (int i = 0; i < packetLength; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n\n");
}

int main(int argc, char **argv)
{
    char* dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    /* check for error */
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Listening on device: %s\n", dev);

    /* set filter to capture only TCP packets on port 80 */
    struct bpf_program filter;
    char* filterString = "tcp port 80";
    bpf_u_int32 subnetMask, ip;
    if (pcap_lookupnet(dev, &ip, &subnetMask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        subnetMask = 0;
    }
    if (pcap_compile(handle, &filter, filterString, 0, subnetMask) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filterString, pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filterString, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* loop and capture packets */
    pcap_loop(handle, -1, packetHandler, NULL);

    /* cleanup */
    pcap_freecode(&filter);
    pcap_close(handle);

    return EXIT_SUCCESS;
}