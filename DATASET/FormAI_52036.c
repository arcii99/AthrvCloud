//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: paranoid
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_IN_LINE 128

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    int *counter = (int *) args;
    (*counter)++;

    printf("Packet #%d:\n", *counter);
    printf("    Length: %d\n", header->len);
    printf("    Time: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("    Src IP: %d.%d.%d.%d\n", packet[26], packet[27], packet[28], packet[29]);
    printf("    Dest IP: %d.%d.%d.%d\n", packet[30], packet[31], packet[32], packet[33]);
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_expression[MAX_CHARS_IN_LINE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 0;

    // Get device to listen on
    char *device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        printf("Error finding default device: %s\n", errbuf);
        return 1;
    }
    printf("Listening on device: %s\n", device);

    // Get network mask and IP address of device
    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        printf("Error getting network and mask: %s\n", errbuf);
        return 1;
    }

    // Open device for sniffing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    // Enable promiscuous mode
    if (pcap_set_promisc(handle, 1) != 0) {
        printf("Error setting promiscuous mode.\n");
        return 1;
    }

    // Compile filter
    printf("Enter BPF filter expression: ");
    fgets(filter_expression, MAX_CHARS_IN_LINE, stdin);
    if (pcap_compile(handle, &fp, filter_expression, 0, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set filter
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Loop and capture packets
    pcap_loop(handle, -1, process_packet, (u_char *) &num_packets);

    // Cleanup
    printf("Captured %d packets.\n", num_packets);
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}