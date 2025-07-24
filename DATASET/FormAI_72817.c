//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured! Size: %d bytes\n", header->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *handle; // Session handle
    struct bpf_program fp; // The compiled filter expression
    char filter_exp[] = "ip"; // The filter expression
    bpf_u_int32 mask; // The netmask of our sniffing device
    bpf_u_int32 net; // The IP of our sniffing device
    int num_packets = 10; // Number of packets to capture

    // Step 1: Get device list
    pcap_if_t *alldevsp;
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        printf("Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Step 2: Set device to use
    if (pcap_lookupnet(alldevsp->name, &net, &mask, errbuf) == -1) {
        printf("Error getting device information: %s\n", errbuf);
        return 1;
    }

    // Step 3: Open device for sniffing
    handle = pcap_open_live(alldevsp->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    // Step 4: Compile and apply filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Step 5: Start sniffing
    printf("Starting packet capture...\n");
    pcap_loop(handle, num_packets, capture_packet, NULL);

    // Step 6: Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Packet capture complete.\n");

    return 0;
}