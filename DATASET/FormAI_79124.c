//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: relaxed
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pcap.h>

void packet_handler(u_char *user_data, const struct pcap_pkthdr *pkt_info, const u_char *pkt_data) {
    printf("Packet captured with length %d\n", pkt_info->len);
}

int main(int argc, char **argv) {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // get the default network interface
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error finding default device: %s\n", errbuf);
        return 1;
    }

    // open the network interface for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s for capturing: %s\n", dev, errbuf);
        return 1;
    }

    // set a filter to only capture packets with destination port 80 (HTTP)
    struct bpf_program filter;
    char *filter_exp = "udp dst port 80";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter '%s': %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter '%s': %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // start capturing packets
    printf("Capturing packets on device %s...\n", dev);
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}