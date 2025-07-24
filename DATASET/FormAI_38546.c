//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: authentic
// This is an example program to monitor network packets using C language.

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    static int count = 1; // keeps track of packet count

    // define ethernet header
    struct ether_header *eth_header = (struct ether_header *) packet;

    printf("Packet number %d:\n", count);

    // print source and destination MAC addresses
    printf("\tSource MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth_header->ether_shost[0], eth_header->ether_shost[1], eth_header->ether_shost[2], eth_header->ether_shost[3], eth_header->ether_shost[4], eth_header->ether_shost[5]);
    printf("\tDestination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth_header->ether_dhost[0], eth_header->ether_dhost[1], eth_header->ether_dhost[2], eth_header->ether_dhost[3], eth_header->ether_dhost[4], eth_header->ether_dhost[5]);

    // print packet length
    printf("\tPacket length: %d\n", header->len);

    // pass the packet to higher layers (IP or TCP)
    const u_char *payload = packet + sizeof(struct ether_header);

    // print packet payload
    int payload_length = header->len - sizeof(struct ether_header);
    printf("\tPayload (%d bytes):\n", payload_length);
    for (int i = 0; i < payload_length; i++)
    {
        printf("%02x ", *(payload + i));
    }
    printf("\n\n");

    count++; // increment packet count
}

int main(int argc, char **argv)
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // open network device for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, true, -1, error_buffer);
    if (!handle)
    {
        fprintf(stderr, "Error opening device: %s\n", error_buffer);
        exit(1);
    }

    // filter for TCP packets only
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // start packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}