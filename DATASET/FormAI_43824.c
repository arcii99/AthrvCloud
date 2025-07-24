//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> 

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = NULL;
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    char filter_exp[] = "tcp";
    int num_packets = 10;
    int timeout_ms = 1000;

    // Get the device to capture on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    printf("Capturing on device: %s\n", dev);

    // Get the net and mask information for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, timeout_ms, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Apply the filter expression to the device
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets
    pcap_loop(handle, num_packets, handle_packet, NULL);

    // Close the device
    pcap_close(handle);

    printf("Finished capturing %d packets\n", num_packets);

    return 0;
}

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured (length %d)\n", header->len);
    // Do something with the packet here
}