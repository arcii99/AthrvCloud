//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: happy
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void happy_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Yay! A happy packet captured!\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "src host happy_ip_address";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    if (argc != 2) {
        fprintf(stderr, "Oopsie! Usage: %s happy_interface\n", argv[0]);
        return (1);
    }

    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Oopsie! Can't get network IP and mask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Oopsie! Can't open interface %s: %s\n", argv[1], errbuf);
        return (2);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Oopsie! Can't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return (2);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Oopsie! Can't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return (2);
    }

    printf("Hooray! Starting the happy packet capture on %s...\n", argv[1]);

    pcap_loop(handle, 0, happy_packet_handler, NULL);

    printf("Woohoo! Capture complete.\n");

    pcap_freecode(&fp);
    pcap_close(handle);

    return (0);
}