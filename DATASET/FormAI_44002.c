//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

struct packet_data{
    struct ether_header eth;
    struct iphdr ip;
    struct tcphdr tcp;
    char data[100];
};

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {

    struct packet_data *data = (struct packet_data*)packet;
    printf("Source MAC: %s\n", ether_ntoa((const struct ether_addr *)&data->eth.ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((const struct ether_addr *)&data->eth.ether_dhost));

    if(ntohs(data->eth.ether_type) == ETHERTYPE_IP) {
        printf("Source IP: %s\n", inet_ntoa((*(struct in_addr *)&data->ip.saddr)));
        printf("Destination IP: %s\n", inet_ntoa((*(struct in_addr *)&data->ip.daddr)));

        if(data->ip.protocol == IPPROTO_TCP) {
            printf("Source Port: %d\n", ntohs(data->tcp.source));
            printf("Destination Port: %d\n", ntohs(data->tcp.dest) );
            printf("Data: %s\n", data->data);
        }
    }
}

int main(int argc, char **argv) {

    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }

    printf("Device: %s\n", dev);

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    pcap_loop(handle, -1, packet_handler, NULL);
    pcap_close(handle);
    return(0);
}