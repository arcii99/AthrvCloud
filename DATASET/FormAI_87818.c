//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Define the maximum packet size */
#define MAX_PACKET_SIZE 65535

/* Define the maximum number of packets to capture */
#define MAX_PACKETS_TO_CAPTURE 100

/* Define the capture device */
#define DEVICE "eth0"

/* Define the capture filter */
#define FILTER "(tcp or udp) and not broadcast and not multicast"

/* Define the global packet count variable */
int packet_count = 0;

/* Define the packet handler function */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    /* Increment the packet count */
    packet_count++;

    /* Print packet timestamp and length */
    printf("Packet %d:\n", packet_count);
    printf("    Timestamp: %s", ctime((const time_t*)&header->ts.tv_sec));
    printf("    Length: %d bytes\n", header->len);
}

int main(int argc, char* argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    /* Retrieve the mask of the first network interface */
    if (pcap_lookupnet(DEVICE, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: pcap_lookupnet: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Open the capture device */
    handle = pcap_open_live(DEVICE, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: pcap_open_live: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Compile the capture filter */
    if (pcap_compile(handle, &fp, FILTER, 0, net) == -1) {
        fprintf(stderr, "Error: pcap_compile: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Set the capture filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: pcap_setfilter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    /* Capture packets */
    pcap_loop(handle, MAX_PACKETS_TO_CAPTURE, packet_handler, NULL);

    /* Print packet count */
    printf("Captured %d packets\n", packet_count);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}