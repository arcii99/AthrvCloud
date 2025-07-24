//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 net, mask;

    // Check if file name is provided
    if(argc != 2) {
        printf("Usage: %s [file_name]\n", argv[0]);
        return 1;
    }

    // Open the capture file
    handle = pcap_open_offline(argv[1], errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error opening file: %s\n", errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error applying filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    struct tm *ltime;
    char timestr[16];
    struct timeval ts;
    int i=0;

    // Get packet timestamp and convert to human-readable format
    ts = header->ts;
    ltime = localtime(&ts.tv_sec);
    strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);

    // Print packet information
    printf("%s.%.6d len:%d\n", timestr, (int)ts.tv_usec, header->len);

    for(i=0; i<header->len; i++) {
        if(i%16 == 0) {
            printf("\n%04x ", i);
        }
        printf("%02x ", pkt_data[i]);
    }
    printf("\n\n");
}