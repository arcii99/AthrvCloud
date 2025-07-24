//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    // Print out the packet length
    printf("Packet length: %d\n", pkthdr->len);
}

int main(int argc, char *argv[])
{
    pcap_t *handle; // Handle for opened pcap session
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for storing error messages
    struct bpf_program fp; // Compiled filter program
    char filter_exp[] = "port 80"; // Filter expression
    bpf_u_int32 net; // IP address of the device
    bpf_u_int32 mask; // Netmask of the device
    struct pcap_pkthdr header; // Packet header struct


    // Find the first available device
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "No device was found: %s\n", errbuf);
        return 1;
    }

    printf("Device found: %s\n", dev);

    // Get the properties of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    printf("Device is open for capturing.\n");

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Set the filter for the device
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Capture the packets
    pcap_loop(handle, -1, packetHandler, NULL);

    // Close the session
    pcap_close(handle);

    return 0;
}