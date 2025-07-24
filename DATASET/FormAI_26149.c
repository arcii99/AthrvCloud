//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    int i;
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s filter\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open device for live capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        fprintf(stderr, "Unable to open live capture device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Lookup net and mask of the device
    if(pcap_lookupnet("eth0", &net, &mask, errbuf) == -1)
    {
        fprintf(stderr, "Unable to lookup net and mask of the device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile and apply packet filter
    if(pcap_compile(handle, &fp, argv[1], 0, net) == -1)
    {
        fprintf(stderr, "Unable to compile packet filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if(pcap_setfilter(handle, &fp) == -1)
    {
        fprintf(stderr, "Unable to apply packet filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets
    if(pcap_loop(handle, 0, packet_handler, NULL) == -1)
    {
        fprintf(stderr, "Unable to capture packets: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return EXIT_SUCCESS;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    int i;
    printf("Packet of length %d captured\n", header->len);
    for(i = 0; i < header->len; i++)
    {
        printf("%02x ", pkt_data[i]);
        if((i+1) % 16 == 0) printf("\n");
    }
    printf("\n");
}