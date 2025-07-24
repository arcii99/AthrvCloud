//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv)
{
    char err_buff[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 net;

    // Step 1: Open pcap session
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, err_buff);
    if (handle == NULL) {
        fprintf(stderr, "Error opening pcap session: %s\n", err_buff);
        exit(EXIT_FAILURE);
    }

    // Step 2: Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression\n");
        exit(EXIT_FAILURE);
    }

    // Step 3: Set filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter expression\n");
        exit(EXIT_FAILURE);
    }

    // Step 4: Capture packets
    if (pcap_loop(handle, -1, packet_handler, NULL) == -1) {
        fprintf(stderr, "Error capturing packets\n");
        exit(EXIT_FAILURE);
    }

    // Step 5: Close pcap session
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured!\n");

    // Do something with the packet data
    // ...
}