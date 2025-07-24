//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: recursive
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pcap_lookupnet(argv[1], &ip, &subnet_mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s\n", argv[1]);
        ip = 0;
        subnet_mask = 0;
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    static int count = 0;
    count++;

    printf("Packet Count: %d\n", count);
    printf("Packet size: %d bytes\n", header->len);
    printf("Epoch Time: %d:%d seconds\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("\n");
    
    pcap_dump(param, header, pkt_data);
}