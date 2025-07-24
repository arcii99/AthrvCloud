//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <netinet/ip.h>
#include <netinet/ether.h>
#include <arpa/inet.h>

pcap_t* handle;

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ethhdr));
    struct in_addr ip_address;
    char source_ip[INET_ADDRSTRLEN];

    memset(&ip_address, 0, sizeof(ip_address));
    memset(source_ip, 0, sizeof(source_ip));

    ip_address.s_addr = ip_header->saddr;
    inet_ntop(AF_INET, &ip_address, source_ip, INET_ADDRSTRLEN);

    printf("Source IP: %s\n", source_ip);
}

void stop_capture(int signum) {
    pcap_breakloop(handle);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev, *filter_expression;
    bpf_u_int32 net, mask;
    struct bpf_program fp;
    int result;

    if (argc != 3) {
        printf("Usage: packet-capture <interface_name> <filter_expression>\n");
        exit(1);
    }

    dev = argv[1];
    filter_expression = argv[2];

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Could not get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Could not open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_expression, 0, net) == -1) {
        printf("Could not parse filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Could not install filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    signal(SIGINT, stop_capture); // Stop capturing packets on Ctrl+C

    while (1) {
        result = pcap_dispatch(handle, 0, handle_packet, NULL);

        if (result == -1) {
            printf("Error occurred while capturing packet: %s\n", pcap_geterr(handle));
            exit(1);
        } else if (result == 0) {
            printf("No more packets in the queue.\n");
        }
    }

    pcap_close(handle);

    return 0;
}