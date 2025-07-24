//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{   
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr packet_header;
    struct bpf_program filter;
    bpf_u_int32 subnet_mask, ip_address;

    // Get device name
    char *device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        printf("Couldn't find default device: %s\n", error_buffer);
        return 1;
    }

    // Get IP and Subnet Mask
    if (pcap_lookupnet(device, &ip_address, &subnet_mask, error_buffer) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", device, error_buffer);
        return 1;
    }

    // Open device for capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", device, error_buffer);
        return 1;
    }

    // Compile and apply filter
    if (pcap_compile(handle, &filter, "port 80", 0, ip_address) == -1) {
        printf("Couldn't parse filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Couldn't install filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured with length: %d\n", header->len);
}