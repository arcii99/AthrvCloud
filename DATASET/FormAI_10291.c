//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char *device;                    // The device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE];   // Error string buffer
    pcap_t *handle;                  // Session handle
    struct bpf_program fp;           // compiled filter expression
    char filter_exp[] = "tcp port 80"; // Filter expression
    bpf_u_int32 net;                 // The IP of our sniffing device
    bpf_u_int32 mask;                // The subnet mask of our sniffing device

    // Find a device to sniff on
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Sniffing on device: %s\n", device);

    // Get the network and mask of the sniffing device
    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device: %s\n", device);
        net = 0;
        mask = 0;
    }

    // Open the specified device for sniffing.
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return(2);
    }

    // Compile and apply filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // End sniffing session
    pcap_close(handle);
    return(0);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured with length: %d\n", header->len);
}