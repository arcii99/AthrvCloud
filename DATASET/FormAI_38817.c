//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//define the maximum packet size
#define MAX_PACKET_SIZE 2048

void print_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *interface = NULL;
    char *filter = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    if (argc < 2) {
        printf("Usage: %s [interface] [filter]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    interface = argv[1];

    if (argc >= 3) {
        filter = argv[2];
    }

    //get the network number and mask of the interface
    if (pcap_lookupnet(interface, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", interface, errbuf);
        net = 0;
        mask = 0;
    }

    //open the interface for capturing
    handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", interface, errbuf);
        exit(EXIT_FAILURE);
    }

    //compile the filter expression
    if (pcap_compile(handle, &fp, filter, 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter %s: %s\n", filter, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    //apply the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    //start capturing packets
    pcap_loop(handle, -1, print_packet, NULL);

    //cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}

void print_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int i, j;
    printf("\nPacket Captured\n");

    //print the packet length
    printf("Length: %d\n", header->len);

    //print the packet data
    for (i = 0; i < header->len; i++) {
        if (i % 16 == 0) {
            printf("\t");
        }
        printf("%02x ", packet[i]);

        if (i == header->len - 1) {
            for (j = 0; j < 15 - i % 16; j++) {
                printf("   ");
            }
            printf("\t");
        }
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    printf("\n");
}