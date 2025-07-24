//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: invasive
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1;
    printf("Packet %d\n", count);
    printf("Length of the packet: %d\n", header->len);
    count++;
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;

    // open the network device for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 0, 1000, errbuf);
    if (handle == NULL) {
        printf("Could not open device for packet capture: %s\n", errbuf);
        return 1;
    }

    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Could not compile filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // apply the filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Could not apply filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    printf("Listening for packets...\n");

    // start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // close the handle
    pcap_close(handle);

    return 0;
}