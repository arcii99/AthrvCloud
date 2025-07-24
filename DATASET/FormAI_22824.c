//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // print packet header information
    printf("Packet length %d\n", header->len);
}

int main(int argc, char **argv)
{
    char *interface = "eth0"; // interface to listen on
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "ip";
    bpf_u_int32 net, mask;

    // get network interface and netmask
    if (pcap_lookupnet(interface, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device %s\n", interface);
        net = 0;
        mask = 0;
    }

    // open device for capturing
    handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Can't open device %s: %s\n", interface, errbuf);
        return -1;
    }

    // compile filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    // apply filter to capture only IP packets
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    // start loop to capture packets until interrupted
    pcap_loop(handle, 0, process_packet, NULL);

    // cleanup and close handle
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}