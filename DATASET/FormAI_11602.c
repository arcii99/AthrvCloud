//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Check if a network interface is specified
    if (argc < 2) {
        printf("Usage: %s [interface]\n", argv[0]);
        return 1;
    }

    // Find the network interface and check it can be opened
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        printf("Error: Couldn't get netmask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }

    // Open the network interface in promiscuous mode
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: Couldn't open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    // Compile and apply the filter to the packet capture handle
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error: Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error: Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet length
    printf("Packet length: %d\n", header->len);
}