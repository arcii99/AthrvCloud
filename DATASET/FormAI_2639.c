//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // Let's do something mind-bending!
    printf("I am the Matrix - monitoring network packets from within!\n");
}

int main(int argc, char **argv)
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "ip";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 10;

    // Start monitor mode
    printf("Initializing packet monitor...\n");
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Failed to open monitor device: %s\n", errbuf);
        return 1;
    }

    // Compile and apply packet filter
    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        printf("Failed to get network info: %s\n", errbuf);
        return 1;
    }
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Failed to compile packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Failed to apply packet filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Starting to capture packets...\n");
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Close monitor mode
    printf("Closing packet monitor...\n");
    pcap_close(handle);
    return 0;
}