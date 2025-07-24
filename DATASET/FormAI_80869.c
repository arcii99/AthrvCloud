//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n"); // Peaceful message
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp"; // Filter for TCP packets
    bpf_u_int32 net = 0;
    bpf_u_int32 mask = 0;
    int timeout = 1000; // 1 second timeout
    int num_packets = 10; // Capture 10 packets

    // Find a suitable network device
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get network device information
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open network device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, timeout, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets
    if (pcap_loop(handle, num_packets, handle_packet, NULL) == -1) {
        fprintf(stderr, "Couldn't capture packets: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Close network device
    pcap_close(handle);

    return EXIT_SUCCESS;
}