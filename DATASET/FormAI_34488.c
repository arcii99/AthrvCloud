//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: scientific
/* Network Packet Monitoring Program */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[])
{
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;

    // Get default device
    device = pcap_lookupdev(error_buffer);
    if (device == NULL)
    {
        fprintf(stderr, "Error finding default device: %s\n", error_buffer);
        return 1;
    }

    // Get network details for device
    if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1)
    {
        fprintf(stderr, "Error getting network details for %s: %s\n", device, error_buffer);
        return 1;
    }

    // Open device for sniffing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening device %s: %s\n", device, error_buffer);
        return 1;
    }

    // Compile filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1)
    {
        fprintf(stderr, "Error compiling filter expression '%s': %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Set filter
    if (pcap_setfilter(handle, &filter) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start sniffing loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close device
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Capture length: %d bytes\n", header->caplen);
    printf("Packet length: %d bytes\n", header->len);
    printf("Packet data: ");

    // Print packet data
    for (int i = 0; i < header->caplen; i++)
    {
        if (i % 16 == 0)
        {
            printf("\n");
        }
        printf("%02x ", packet[i]);
    }

    printf("\n\n");
}