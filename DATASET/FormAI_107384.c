//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
/* Yeah! Let's capture some packets in style */
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *header,
    const u_char *packet
)
{
    printf("Hey, look at that packet..\n");
    /* Do some packet analysis here! */
}

int main(int argc, char** argv)
{
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "port 80"; /* Capture only HTTP traffic */
    bpf_u_int32 net;

    /* Let's open up a live capture session */
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Oops! Couldn't open device: %s\n", errbuf);
        exit(1);
    }

    /* Let's compile our capture filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Oops! Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    /* Enable our capture filter */
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Oops! Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    /* Capture some packets */
    printf("Alright, let's start capturing some packets!\n");
    pcap_loop(handle, -1, my_packet_handler, NULL);

    /* Cleanup */
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}