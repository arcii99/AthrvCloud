//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Find the default network interface and mask
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get default network interface: %s\n", errbuf);
        net = 0;
        mask = 0;
    }

    // Open device for sniffing
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Can't open device eth0: %s\n", errbuf);
        return 1;
    }

    // Compile and apply filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Loop and capture packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // Print packet details
    printf("Packet capture length: %d\n", header->caplen);
    printf("Packet total length: %d\n", header->len);
}